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

#include <baremetal/syscalls.h>

#include <bmfs/disk.h>
#include <bmfs/limits.h>

#include "file.h"

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

