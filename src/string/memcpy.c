// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

void *memcpy(void *dst, const void *src, size_t count) {
	unsigned char *dst8 = dst;
	const unsigned char *src8 = src;
	for (size_t i = 0; i < count; i++) {
		dst8[i] = src8[i];
	}
	return dst;
}
