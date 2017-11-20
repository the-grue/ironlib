// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/sstream.h>

void ironlib_sstream_set_buf(struct ironlib_sstream *sstream,
                             void *buf, size_t bufsize) {
	sstream->buf = (char *) buf;
	sstream->bufsize = bufsize;
}
