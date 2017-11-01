// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdlib.h>

#include <baremetal/baremetal.h>

#ifndef BAREMETAL_PAGE_SIZE
#define BAREMETAL_PAGE_SIZE (2 * 1024 * 1024)
#endif

void *malloc(size_t size) {

	if (size > BAREMETAL_PAGE_SIZE)
		return NULL;

	void *addr = NULL;

	b_mem_allocate(&addr, 1);

	return addr;
}

void free(void *addr) {
	if (addr != NULL)
		b_mem_release(&addr, 1);
}
