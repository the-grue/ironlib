// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef IRONLIB_BAREMETAL_FILE_H
#define IRONLIB_BAREMETAL_FILE_H

#include <stdio.h>

#include <bmfs/disk.h>

#include "disk.h"

enum ironlib_filemode {
	READ,
	WRITE
};

struct ironlib_file {
	struct baremetal_disk disk_handle;
	struct BMFSDisk disk;
	struct BMFSEntry file_entry;
	enum ironlib_filemode mode;
	uint64_t offset;
	uint64_t size;
};

#endif // IRONLIB_BAREMETAL_FILE_H
