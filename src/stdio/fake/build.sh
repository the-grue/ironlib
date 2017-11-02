#!/bin/sh

$CC $CFLAGS -c fclose.c -o fclose.o
$CC $CFLAGS -c fopen.c -o fopen.o
$CC $CFLAGS -c feof.c -o feof.o
$CC $CFLAGS -c fread.c -o fread.o
$CC $CFLAGS -c fwrite.c -o fwrite.o
