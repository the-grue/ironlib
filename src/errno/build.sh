#!/bin/sh

CFLAGS="$CFLAGS -I../../include"

$CC $CFLAGS -c errno.c -o errno.o
