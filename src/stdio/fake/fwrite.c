// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

size_t fwrite(const void *buf, size_t element_size,
              size_t element_count, FILE *file) {
	(void) buf;
	(void) element_size;
	(void) element_count;
	(void) file;
	return 0;
}

