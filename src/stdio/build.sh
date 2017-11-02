#!/bin/sh

$CC $CFLAGS -c puts.c -o puts.o
$CC $CFLAGS -c stdout.c -o stdout.o

cd baremetal
./build.sh
cd ..
