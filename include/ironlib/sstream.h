// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef IRONLIB_SSTREAM_H
#define IRONLIB_SSTREAM_H

#include <ironlib/stream.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ironlib_sstream {
	/** @brief The base stream structure. */
	struct ironlib_stream base;
	/** The pointer to the string associated
	 * with the string. */
	char *buf;
	/** The number of bytes that the stream
	 * may write to buffer. */
	size_t bufsize;
};

void ironlib_sstream_init(struct ironlib_sstream *sstream);

void ironlib_sstream_set_buf(struct ironlib_sstream *sstream,
                             void *buf, size_t bufsize);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // IRONLIB_SSTREAM_H
