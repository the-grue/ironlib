#!/bin/sh

$CC $CFLAGS -c puts.c -o puts.o
$CC $CFLAGS -c stdout.c -o stdout.o

cd ${TARGET}
./build.sh
cd ..
