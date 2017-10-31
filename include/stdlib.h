// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file stdlib.h
/// @brief A group of general purpose functions
/// and definitions.

/// @defgroup baremetal-stdlib Stdlib
/// @brief A group of general purpose functions
/// and definitions.

#ifndef BAREMETAL_LIBC_STDLIB_H
#define BAREMETAL_LIBC_STDLIB_H

#include <baremetal/types.h>

/// @brief Used to represent an invalid
/// address.
/// @ingroup baremetal-stdlib
#define NULL ((void *) 0)

/// @brief Returned by main if an error
/// occured within the program.
/// @ingroup baremetal-stdlib
#define EXIT_FAILURE 1

/// @brief Returned by main if a program
/// exited without any errors.
/// @ingroup baremetal-stdlib
#define EXIT_SUCCESS 0

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Resizes a block of memory to
/// fit @p size number of bytes.
/// @param addr The address to a block of
/// memory returned by @ref malloc, @ref calloc
/// or @ref realloc. This parameter may also be
/// @ref NULL, in which case a new block of memory
/// is created.
/// @param size The number of bytes the new block
/// should fit.
/// @returns The address to the new block of memory
/// on success, @ref NULL on failure.
/// @ingroup baremetal-stdlib
void *realloc(void *addr, size_t size);

/// @brief Allocates a block of memory, of
/// size @p size.
/// @param size The number of bytes to allocate.
/// @returns If the function is successfull, then
/// the address to the memory block is returned.
/// Otherwise, @ref NULL is returned.
/// @ingroup baremetal-stdlib
void *malloc(size_t size);

/// @brief Allocates a block of memory. The
/// size of the block is the product of @p n
/// and @p count. The memory is zeroed before
/// it is returned.
/// @param n The number of elements to allocate.
/// @param count The size of each element.
/// @returns If the function is successful, then
/// the address of the block of memory is returned.
/// Otherwise, @ref NULL is returned.
/// @ingroup baremetal-stdlib
void *calloc(size_t n, size_t count);

/// @brief Releases a block of memory back to
/// the system.
/// @param addr The address of the block of memory
/// returned by @ref malloc or @ref calloc.
/// @ingroup baremetal-stdlib
void free(void *addr);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BAREMETAL_LIBC_STDLIB_H
