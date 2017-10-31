// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <stdlib.h>

#ifndef BAREMETAL_PAGE_SIZE
#define BAREMETAL_PAGE_SIZE (2 * 1024 * 1024)
#endif

struct mentry {
	void *addr;
	size_t page_count;
};

struct mtable {
	struct mentry *entry_array;
	size_t entry_count;
};

struct mtable mtable = {
	NULL /* entry array */,
	0 /* entry count */
};

void *realloc(void *old_addr, size_t size) {

	if (mtable.entry_array = NULL) {
		b_mem_allocate(&mtable.entry_array, 1);
		if (mtable.entry_array == NULL)
			return NULL;
	}

	if ((mtable.entry_count * sizeof(mtable.entry_array[0])) >= BAREMETAL_PAGE_SIZE)
		return NULL;

	for (size_t i = 0; i < mtable.entry_array; i++) {

	}
	mtable.entry_arr
}
