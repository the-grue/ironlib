#!/bin/sh

mkdir -p $DESTDIR$PREFIX/lib
mkdir -p $DESTDIR$PREFIX/include

cp libc.a $DESTDIR$PREFIX/lib/

cp include/errno.h \
   include/limits.h \
   include/stdio.h \
   include/stdlib.h \
   include/stdint.h \
   include/string.h \
   $DESTDIR$PREFIX/include/
