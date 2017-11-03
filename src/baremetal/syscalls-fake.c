// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <baremetal/syscalls.h>

void b_output(const char *str) {
	(void) str;
}

void b_output_chars(const char *str, unsigned long nbr) {
	(void) str;
	(void) nbr;
}

unsigned long b_input(char *str, unsigned long nbr) {
	(void) str;
	(void) nbr;
	return 0;
}

char b_input_key(void) {
	return 0;
}

unsigned long b_smp_set(void *codeptr, void *dataptr, unsigned long cpu) {
	(void) codeptr;
	(void) dataptr;
	(void) cpu;
	return 0;
}

unsigned long b_smp_config() {
	return 0;
}

unsigned long b_mem_allocate(void **mem, unsigned long nbr) {
	(void) mem;
	(void) nbr;
	return 0;
}

unsigned long b_mem_release(void **mem, unsigned long nbr) {
	(void) mem;
	(void) nbr;
	return 0;
}

void b_ethernet_tx(const void *mem, unsigned long len, unsigned long iid) {
	(void) mem;
	(void) len;
	(void) iid;
}

unsigned long b_ethernet_rx(void *mem, unsigned long iid) {
	(void) mem;
	(void) iid;
	return 0;
}

unsigned long b_disk_read(void *mem, unsigned long start, unsigned long num, unsigned long disknum) {
	(void) mem;
	(void) start;
	(void) num;
	(void) disknum;
	return 0;
}

unsigned long b_disk_write(const void *mem, unsigned long start, unsigned long num, unsigned long disknum) {
	(void) mem;
	(void) start;
	(void) num;
	(void) disknum;
	return 0;
}

unsigned long b_system_config(unsigned long function, unsigned long var) {
	(void) function;
	(void) var;
	return 0;
}

void b_system_misc(unsigned long function, void* var1, void* var2) {
	(void) function;
	(void) var1;
	(void) var2;
}
