#!/bin/sh

$CC $CFLAGS -c puts.c -o puts.o
$CC $CFLAGS -c stdout.c -o stdout.o

# Make sure we're not building BareMetal-specific
# code in Travis CI, at least until we can install
# the dependencies.
if test -z "$TRAVIS_BUILD"; then
	cd baremetal
	./build.sh
	cd ..
fi
