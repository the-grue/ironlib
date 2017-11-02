#!/bin/sh

CFLAGS="${CFLAGS} -I ../../../include"

$CC $CFLAGS -c malloc.c -o malloc.o
$CC $CFLAGS -c free.c -o free.o
