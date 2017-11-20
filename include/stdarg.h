// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file

#ifndef IRONLIB_STDARG_H
#define IRONLIB_STDARG_H

#ifdef __cplusplus
extern "C" {
#endif

typedef __builtin_va_list va_list;

#define va_start(ap, param) __builtin_va_start(ap, param)

#define va_end(ap) __builtin_va_end(ap)

#define va_arg(ap, type) __builtin_va_arg(ap, type)

#define va_copy(dst, src) __builtin_va_copy(dst, src)

#ifdef __cplusplus
} // extern "C"
#endif

#endif // IRONLIB_STDARG_H
