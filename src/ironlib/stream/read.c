// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/stream.h>

size_t ironlib_stream_read(struct ironlib_stream *stream,
                           void *buf, size_t buf_size) {
	if (stream->read == NULL)
		return 0ULL;
	else
		return stream->read(stream->data, buf, buf_size);
}
