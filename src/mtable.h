// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef BAREMETAL_MTABLE_H
#define BAREMETAL_MTABLE_H

#include <baremetal/types.h>

#ifndef BAREMETAL_PAGE_SIZE
#define BAREMETAL_PAGE_SIZE (2 * 1024 * 1024)
#endif

struct mentry {
	void *addr;
	size_t size;
	size_t pages;
};

struct mtable {
	struct mentry *entry_array;
	size_t entry_count;
	size_t entry_max;
	size_t page_size;
	int (*allocate_pages)(void **addr, size_t pages);
	int (*release_pages)(void *addr, size_t pages);
};

extern struct mtable global_mtable;

void mtable_init(struct mtable *table);

void mtable_free(struct mtable *table);

void *mtable_malloc(struct mtable *table, size_t size);

void *mtable_realloc(struct mtable *table, void *addr, size_t size);

#endif // BAREMETAL_MTABLE_H
