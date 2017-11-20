// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/stream.h>

#ifndef NULL
#define NULL ((void *) 0x00)
#endif

void ironlib_stream_init(struct ironlib_stream *stream) {
	stream->data = NULL;
	stream->get_pos = NULL;
	stream->set_pos = NULL;
	stream->write = NULL;
	stream->read = NULL;
}
