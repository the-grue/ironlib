// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

void *memset(void *dst, int value, size_t size) {
	unsigned char value8 = (unsigned char) value;
	unsigned char *dst8 = (unsigned char *) dst;
	for (size_t i = 0; i < size; i++) {
		dst8[i] = value8;
	}
	return dst;
}
