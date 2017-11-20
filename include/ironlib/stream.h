// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef IRONLIB_STREAM_H
#define IRONLIB_STREAM_H

#include <stdarg.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ironlib_stream {
	void *data;
	int (*set_pos)(void *data, unsigned long long int position);
	int (*get_pos)(void *data, unsigned long long int *position);
	size_t (*read)(void *data, void *buf, size_t buf_size);
	size_t (*write)(void *data, const void *buf, size_t buf_size);
};

void ironlib_stream_init(struct ironlib_stream *stream);

void ironlib_stream_done(struct ironlib_stream *stream);

size_t ironlib_stream_read(struct ironlib_stream *stream,
                           void *buf, size_t buf_size);

size_t ironlib_stream_write(struct ironlib_stream *stream,
                            const void *buf, size_t buf_size);

int ironlib_stream_printf(struct ironlib_stream *stream,
                          const char *fmt, ...);

int ironlib_stream_vprintf(struct ironlib_stream *stream,
                           const char *fmt, va_list args);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // IRONLIB_STREAM_H
