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

#include <baremetal/types.h>

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

/// @brief Standard C file structure.
/// @ingroup baremetal-stdio
typedef struct ironlib_file FILE;

/// @brief The file handle to the standard output.
extern FILE *stdout;

/// @brief Opens a file for reading or writing.
/// @param filename The name of the file to open.
/// @param mode The mode to open the file with.
/// Currently supported modes are 'r' for reading,
/// 'w' for writing and 'b' for binary reading and
/// writing.
/// @returns If the file was opened properly, then
/// a pointer to the file structure is returned. Otherwise,
/// @ref NULL is returned.
/// @ingroup baremetal-stdio
FILE *fopen(const char *filename, const char *mode);

/// @brief Closes a file.
/// @param file A file opened with @ref fopen.
/// This parameter may be @ref NULL, in which
/// case the function does nothing.
/// @ingroup baremetal-stdio
void fclose(FILE *file);

/// @brief Check if the end of the file has been
/// reached.
/// @returns Zero if the end of file has been reached,
/// non-zero otherwise.
/// @ingroup baremetal-stdio
int feof(FILE *file);

/// @brief Read elements from a file. The elements
/// may be of any size between one and @ref SIZE_MAX.
/// @param buf The address of the memory to write the
/// file data to.
/// @param element_size The size of each element.
/// @param element_count The number of elements to read.
/// @returns The number of elements read.
/// @ingroup baremetal-stdio
size_t fread(void *buf, size_t element_size,
             size_t element_count, FILE *file);

size_t fwrite(const void *buf, size_t element_size,
              size_t element_count, FILE *file);

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
