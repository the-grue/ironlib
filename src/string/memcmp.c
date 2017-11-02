// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

int memcmp(const void *a, const void *b, size_t count) {
	const unsigned char *au = (const unsigned char *) a;
	const unsigned char *bu = (const unsigned char *) b;
	for (size_t i = 0; i < count; i++) {
		if (*au != *bu)
			return *au - *bu;
		au++;
		bu++;
	}
	return 0;
}
