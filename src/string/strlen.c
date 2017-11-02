// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <string.h>

size_t strlen(const char *str) {
	size_t i = 0;
	while (str[i] != 0)
		i++;
	return i;
}
