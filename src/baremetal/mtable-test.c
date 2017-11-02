// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include "mtable.h"

#include <assert.h>
#include <stdlib.h>

#define ADDR(addr) ((void *) addr)

const size_t page_size = 16;

struct test_page {
	unsigned char occupied;
	unsigned char *memory;
};

struct test_page pages[4] = {
	{ 0, ADDR(0x1000) },
	{ 0, ADDR(0x1010) },
	{ 0, ADDR(0x1020) },
	{ 0, ADDR(0x1030) }
};

static void reset_pages(void) {
	for (size_t i = 0; i < 4; i++) {
		pages[i].occupied = 0;
	}
}

int allocate_pages(void **addr, size_t page_count) {
	size_t pages_found = 0;
	for (size_t i = 0; i < 4; i++) {
		if (pages[i].occupied == 0) {
			pages_found++;
		} else {
			pages_found = 0;
			continue;
		}
		if (pages_found == page_count) {
			pages[i - pages_found].occupied = 1;
			*addr = pages[i - pages_found].memory;
			return 0;
		}
	}
	return -1;
}

int release_pages(void *addr, size_t page_count) {
	for (size_t i = 0; i < 4; i++) {
		if (pages[i].memory != (unsigned char *) addr) {
			continue;
		}
		while ((i < 4) && (page_count > 0)) {
			pages[i].occupied = 0;
			i++;
			page_count--;
		}
		return 0;
	}
	return -1;
}

static void test_malloc(void) {

	reset_pages();

	struct mtable table;

	mtable_init(&table);
	table.page_size = page_size;
	table.allocate_pages = allocate_pages;
	table.release_pages = release_pages;

	void *addr1 = mtable_malloc(&table, 1);
	assert(addr1 == ADDR(0x1000));
	assert(pages[0].occupied == 1);
	assert(pages[1].occupied == 0);
	assert(pages[2].occupied == 0);
	assert(pages[3].occupied == 0);
}

int main(void) {
	test_malloc();
	return EXIT_SUCCESS;
}

