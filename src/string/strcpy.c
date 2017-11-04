// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

char *strcpy(char *dst, const char *src) {
	size_t i;
	for (i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = 0;
	return dst;
}
