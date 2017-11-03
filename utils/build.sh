#!/bin/sh

CFLAGS="$CFLAGS -std=c99"

$CC $CFLAGS generate-limits.c -o generate-limits
