// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/stream.h>

int ironlib_stream_printf(struct ironlib_stream *stream,
                          const char *fmt, ...) {

	int write_count = 0;

	va_list args;

	va_start(args, fmt);

	write_count = ironlib_stream_vprintf(stream, fmt, args);

	va_end(args);

	return write_count;
}
