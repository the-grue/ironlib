// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdlib.h>

#include <baremetal/syscalls.h>

void free(void *addr) {
	if (addr != NULL)
		b_mem_release(&addr, 1);
}
