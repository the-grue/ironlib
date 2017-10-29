// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <baremetal/baremetal.h>

int puts(const char *str) {
	b_output(str);
	b_output_chars("\n", 1);
	return 0;
}
