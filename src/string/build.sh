#!/bin/sh

$CC $CFLAGS -c memcmp.c -o memcmp.o
$CC $CFLAGS -c memcpy.c -o memcpy.o
$CC $CFLAGS -c strcmp.c -o strcmp.o
$CC $CFLAGS -c strlen.c -o strlen.o
