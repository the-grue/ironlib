#!/bin/sh

$CC $CFLAGS -c memcmp.c -o memcmp.o
$CC $CFLAGS -c memcpy.c -o memcpy.o
$CC $CFLAGS -c memset.c -o memset.o
$CC $CFLAGS -c strcmp.c -o strcmp.o
$CC $CFLAGS -c strcpy.c -o strcpy.o
$CC $CFLAGS -c strlen.c -o strlen.o
