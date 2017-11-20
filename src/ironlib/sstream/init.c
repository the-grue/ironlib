// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/sstream.h>

#ifndef NULL
#define NULL ((void *) 0x00)
#endif

void ironlib_sstream_init(struct ironlib_sstream *sstream) {
	ironlib_stream_init(&sstream->base);
	sstream->buf = NULL;
	sstream->bufsize = 0;
}
