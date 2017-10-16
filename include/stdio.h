// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file stdio.h
/// @brief Standard input and output functions
/// and definitions.

/// @defgroup baremetal-stdio Standard Input and Output
/// @brief Functions and definitions related to standard
/// input and output.

#ifndef BAREMETAL_LIBC_STDIO_H
#define BAREMETAL_LIBC_STDIO_H

/// @brief An indicator that the end of the
/// file has been reached.
/// @ingroup baremetal-stdio
#define EOF (-1)

/// @brief Move the file position relative
/// to the beginning of the file.
/// @ingroup baremetal-stdio
#define SEEK_SET 0

/// @brief Move the file position relative
/// to the current position of the file.
/// @ingroup baremetal-stdio
#define SEEK_CUR 1

/// @brief Move the file position relative
/// to the end of the file.
/// @ingroup baremetal-stdio
#define SEEK_END 2

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Writes a string to the
/// default output.
/// @param str The string to write to
/// the standard output.
/// @returns Zero on success, EOF if
/// an error occured.
/// @ingroup baremetal-stdio
int puts(const char *str);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BAREMETAL_LIBC_STDIO_H
