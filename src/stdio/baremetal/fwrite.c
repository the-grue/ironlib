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

size_t fwrite(const void *buf, size_t element_size,
              size_t element_count, FILE *file) {

	size_t write_size = element_size * element_count;

	if (file == stdout) {
		b_output_chars(buf, write_size);
		return element_count;
	}

	return 0;
}

