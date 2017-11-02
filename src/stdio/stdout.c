// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

struct ironlib_file {
	void *unused;
};

FILE stdout_real;

FILE *stdout = &stdout_real;
