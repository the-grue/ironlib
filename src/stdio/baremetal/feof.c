// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

#include "file.h"

int feof(FILE *file) {

	int64_t current_offset;

	int err = bmfs_disk_tell(&file->disk, &current_offset);
	if (err != 0)
		return 1;

	if (((uint64_t) current_offset) >= (file->offset + file->size))
		return 1;

	return 0;
}
