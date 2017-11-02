// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdio.h>

#include <stdlib.h>

void fclose(FILE *file) {
	free(file);
}
