// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include "disk.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <baremetal/syscalls.h>

void disk_init(struct baremetal_disk *disk) {
	disk->disk_offset = 0;
	// TODO : this must be calculated */
	disk->disk_length = 1024 * 1024 * 6;
};

int disk_seek(void *disk_data, int64_t offset, int whence)
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

int disk_tell(void *disk_data, int64_t *offset)
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

int disk_read(void *disk_data, void *buf, uint64_t buf_len, uint64_t *read_len)
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

int disk_write(void *disk_data, const void *buf, uint64_t buf_len, uint64_t *write_len)
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
