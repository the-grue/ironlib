// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <ironlib/stream.h>

#include <errno.h>
#include <string.h>


static int handle_string(struct ironlib_stream *stream,
                         const char *fmt, va_list args, size_t *j) {

	size_t i = *j;

	if (fmt[i] != 's')
		return -1;

	const char *arg = va_arg(args, const char *);
	if (arg == NULL) {
		errno = EFAULT;
		return -1;
	}

	size_t arg_len = strlen(arg);

	return ironlib_stream_write(stream, arg, arg_len);
}

/* handles an argument */
static int ironlib_stream_arg(struct ironlib_stream *stream,
                              const char *fmt, va_list args, size_t *j) {
	int write_count = -1;

	write_count = handle_string(stream, fmt, args, j);
	if (write_count >= 0)
		return write_count;

	return -1;
}

int ironlib_stream_vprintf(struct ironlib_stream *stream,
                           const char *fmt, va_list args) {
	size_t write_count = 0;
	size_t total_write_count = 0;
	for (size_t i = 0; fmt[i]; i++) {
		if (fmt[i] != '%') {
			write_count = ironlib_stream_write(stream, &fmt[i], 1);
			if (write_count != 1)
				break;
			total_write_count += write_count;
			continue;
		} else if (fmt[i + 1] == '%') {
			write_count = ironlib_stream_write(stream, &fmt[i + 1], 1);
			if (write_count != 1)
				break;
			i++;
			total_write_count += write_count;
			continue;
		} else{
			write_count = ironlib_stream_arg(stream, &fmt[i + 1], args, &i);
			if (write_count == 0)
				break;
			total_write_count += write_count;
			continue;
		}
	}
	return 0;
}
