// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/sstream.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char buf[32];
	struct ironlib_sstream sstream;
	struct ironlib_stream *stream;

	ironlib_sstream_init(&sstream);

	ironlib_sstream_set_buf(&sstream, buf, sizeof(buf));

	stream = &sstream.base;

	int write_count = ironlib_stream_printf(stream, "%s", "string");
	assert(write_count == 6);
	assert(buf[0] == 's');
	assert(buf[1] == 't');
	assert(buf[2] == 'r');
	assert(buf[3] == 'i');
	assert(buf[4] == 'n');
	assert(buf[5] == 'g');

	return 0;
}

