// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

#include <errno.h>
#include <stdint.h>
#include <string.h>

#include <baremetal/baremetal.h>

#include <bmfs/disk.h>
#include <bmfs/limits.h>

FILE stdout_real;

FILE *stdout = &stdout_real;

int puts(const char *str) {
	char newline = '\n';
	b_output(str);
	b_output_chars(&newline, 1);
	return 0;
}

struct baremetal_disk {
	uint64_t disk_offset;
	uint64_t disk_length;
	unsigned char disk_section[4096];
};

static void disk_init(struct baremetal_disk *disk);

static int disk_seek(void *disk_data,
                     int64_t offset,
                     int whence);

static int disk_tell(void *disk_data,
                     int64_t *offset);

static int disk_read(void *disk_data,
                     void *buf,
                     uint64_t buf_len,
                     uint64_t *read_len);

static int disk_write(void *disk_data,
                      const void *buf,
                      uint64_t buf_len,
                      uint64_t *write_len);

enum filemode {
	READ,
	WRITE
};

struct baremetal_file {
	struct baremetal_disk disk_handle;
	struct BMFSDisk disk;
	struct BMFSEntry file_entry;
	enum filemode mode;
	uint64_t offset;
	uint64_t size;
};

FILE *fopen(const char *filename, const char *mode) {

	FILE *file = malloc(sizeof(FILE));

	disk_init(&file->disk_handle);

	file->disk.disk = &file->disk_handle;
	file->disk.seek = disk_seek;
	file->disk.tell = disk_tell;
	file->disk.read = disk_read;
	file->disk.write = disk_write;

	struct BMFSDir root_dir;

	bmfs_dir_init(&root_dir);

	bmfs_disk_read_root_dir(&file->disk, &root_dir);

	struct BMFSEntry *entry = bmfs_dir_find(&root_dir, filename);
	if (entry == NULL) {
		/* file not found */
		errno = ENOENT;
		free(file);
		return NULL;
	} else if (bmfs_entry_is_directory(entry)) {
		/* entry is a directory */
		errno = EISDIR;
		free(file);
		return NULL;
	}

	file->file_entry = *entry;

	if (mode == NULL) {
		errno = EFAULT;
		free(file);
		return NULL;
	} else if ((strcmp(mode, "rb") == 0)
	        || (strcmp(mode, "r") == 0)) {
		file->mode = READ;
	} else if ((strcmp(mode, "rb") == 0)
	        || (strcmp(mode, "r") == 0)) {
		file->mode = WRITE;
	} else {
		/* invalid mode */
		errno = EINVAL;
		free(file);
		return NULL;
	}

	file->offset = entry->StartingBlock * BMFS_BLOCK_SIZE;

	file->size = entry->FileSize;

	int err = bmfs_disk_seek(&file->disk, file->offset, SEEK_SET);
	if (err != 0) {
		/* errno set by disk_seek() */
		free(file);
		return NULL;
	}

	return file;
}

void fclose(FILE *file) {
	free(file);
}

int feof(FILE *file) {

	int64_t current_offset;

	int err = bmfs_disk_tell(&file->disk, &current_offset);
	if (err != 0)
		return 1;

	if (((uint64_t) current_offset) >= (file->offset + file->size))
		return 1;

	return 0;
}

size_t fread(void *buf, size_t element_size,
             size_t element_count, FILE *file) {

	if (file->mode != READ)
		return 0;

	int64_t current_offset;

	int err = bmfs_disk_tell(&file->disk, &current_offset);
	if (err != 0) {
		/* errno set by disk_tell() */
		return 0;
	}

	if (((uint64_t) current_offset) < file->offset) {
		// TODO : better error code?
		errno = EINVAL;
		return 0;
	}

	size_t data_leftover = file->size - ((uint64_t)(current_offset - file->offset));

	size_t read_size = element_size * element_count;
	if (read_size > data_leftover)
		read_size = data_leftover;

	/* don't attempt to read elements that
	 * the file doesn't have. */
	if ((read_size % element_size) != 0)
		read_size -= (read_size % element_size);

	uint64_t read_result = 0;

	err = bmfs_disk_read(&file->disk, buf, read_size, &read_result);
	if (err != 0) {
		errno = -err;
		return 0;
	}

	return read_result / element_size;
}

size_t fwrite(const void *buf, size_t element_size,
              size_t element_count, FILE *file) {

	size_t write_size = element_size * element_count;

	if (file == stdout) {
		b_output_chars(buf, write_size);
		return element_count;
	}

	return 0;
}

static void disk_init(struct baremetal_disk *disk) {
	disk->disk_offset = 0;
	// TODO : this must be calculated */
	disk->disk_length = 1024 * 1024 * 6;
};

static int disk_seek(void *disk_data, int64_t offset, int whence)
{
	struct baremetal_disk *disk = (struct baremetal_disk *) disk_data;

	if (whence == SEEK_SET)
		disk->disk_offset = offset;
	else if (whence == SEEK_END)
		disk->disk_offset = disk->disk_length - offset;
	else if (whence == SEEK_CUR)
		disk->disk_offset += offset;
	else {
		errno = EINVAL;
		return -1;
	}

	return 0;
}

static int disk_tell(void *disk_data, int64_t *offset)
{
	struct baremetal_disk *disk = (struct baremetal_disk *) disk_data;
	if (disk == NULL) {
		errno = EFAULT;
		return -1;
	}

	if (offset == NULL) {
		errno = EFAULT;
		return -1;
	}

	*offset = disk->disk_offset;

	return 0;
}

static int disk_read(void *disk_data, void *buf, uint64_t buf_len, uint64_t *read_len)
{
	struct baremetal_disk *disk = (struct baremetal_disk *) disk_data;
	if (disk == NULL) {
		errno = EFAULT;
		return -1;
	}

	if (buf == NULL) {
		errno = EFAULT;
		return -1;
	}

	uint64_t sections_read;
	uint64_t bytes_read;

	if (buf_len > 4096)
		buf_len = 4096;

	sections_read = b_disk_read(disk->disk_section, disk->disk_offset / 4096, 1, 0);

	bytes_read = sections_read * 4096;
	if (bytes_read > buf_len)
		bytes_read = buf_len;

	if (read_len != NULL)
		*read_len = bytes_read;

	memcpy(buf, &disk->disk_section[disk->disk_offset % 4096], bytes_read);

	disk->disk_offset += bytes_read;

	return 0;
}

static int disk_write(void *disk_data, const void *buf, uint64_t buf_len, uint64_t *write_len)
{
	struct baremetal_disk *disk = (struct baremetal_disk *) disk_data;
	if (disk == NULL) {
		errno = EFAULT;
		return -1;
	}

	if (buf == NULL) {
		errno = EFAULT;
		return -1;
	}

	uint64_t sections_read;
	uint64_t sections_write;
	uint64_t bytes_write;

	sections_read = b_disk_read(disk->disk_section, disk->disk_offset / 4096, 1, 0);
	if (sections_read == 0) {
		errno = EIO;
		return -1;
	}

	memcpy(&disk->disk_section[disk->disk_offset % 4096], buf, buf_len);

	sections_write = b_disk_write(disk->disk_section, disk->disk_offset / 4096, 1, 0);

	bytes_write = sections_write * 4096;
	if (bytes_write > buf_len)
		bytes_write = buf_len;

	if (write_len != NULL)
		*write_len = bytes_write;

	return 0;
}

