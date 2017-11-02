// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <bmfs/disk.h>
#include <bmfs/limits.h>

#include "disk.h"
#include "file.h"

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
