// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef IRONLIB_BAREMETAL_DISK_H
#define IRONLIB_BAREMETAL_DISK_H

#include <stdint.h>

struct baremetal_disk {
	uint64_t disk_offset;
	uint64_t disk_length;
	unsigned char disk_section[4096];
};

void disk_init(struct baremetal_disk *disk);

int disk_seek(void *disk_data,
              int64_t offset,
              int whence);

int disk_tell(void *disk_data,
              int64_t *offset);

int disk_read(void *disk_data,
              void *buf,
              uint64_t buf_len,
              uint64_t *read_len);

int disk_write(void *disk_data,
               const void *buf,
               uint64_t buf_len,
               uint64_t *write_len);

#endif // IRONLIB_BAREMETAL_DISK_H
