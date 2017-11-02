// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include "mtable.h"

#ifndef NULL
#define NULL ((void *) 0x00)
#endif

static int make_more_entries(struct mtable *table) {

	if ((table->allocate_pages == NULL)
	 || (table->release_pages == NULL)) {
		return -1;
	}

	size_t bytes_required = table->entry_max + 32;
	bytes_required *= sizeof(table->entry_array[0]);

	size_t pages_required = (bytes_required + table->page_size) / table->page_size;

	void *addr = NULL;

	int err = table->allocate_pages(&addr, pages_required);
	if (err != 0)
		return err;

	struct mentry *next_entries = (struct mentry *) addr;

	for (size_t i = 0; i < table->entry_count; i++) {
		next_entries[i] = table->entry_array[i];
	}

	size_t old_page_count = 0;

	old_page_count += table->entry_max;
	old_page_count *= sizeof(table->entry_array[0]);
	old_page_count = (old_page_count + table->page_size) / table->page_size;

	table->release_pages(table->entry_array, old_page_count);

	table->entry_array = next_entries;
	table->entry_max += 32;

	return 0;
}

void mtable_init(struct mtable *table) {
	table->entry_array = NULL;
	table->entry_count = 0;
	table->entry_max = 0;
	table->allocate_pages = NULL;
	table->release_pages = NULL;
	table->page_size = 0;
}

void *mtable_malloc(struct mtable *table, size_t size) {

	if (table->entry_count >= table->entry_max) {
		int err = make_more_entries(table);
		if (err != 0)
			return NULL;
	}

	if (table->allocate_pages == NULL)
		return NULL;

	size_t page_count = (size + table->page_size) / table->page_size;

	void *addr = NULL;

	int err = table->allocate_pages(&addr, page_count);
	if (err != 0)
		return NULL;

	struct mentry *entry = &table->entry_array[table->entry_count];

	entry->addr = addr;
	entry->size = size;
	entry->pages = page_count;

	return addr;
}

