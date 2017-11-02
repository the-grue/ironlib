// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

int strcmp(const char *a, const char *b) {
	const unsigned char *au = (const unsigned char *) a;
	const unsigned char *bu = (const unsigned char *) b;
	while (*au && (*au == *bu)) {
		au++;
		bu++;
	}
	return *au - *bu;
}
