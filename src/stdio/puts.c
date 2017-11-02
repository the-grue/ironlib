// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

#include <string.h>

int puts(const char *str) {
	size_t len = strlen(str);
	fwrite(str, 1, len, stdout);
	fwrite("\n", 1, 1, stdout);
	return 0;
}
