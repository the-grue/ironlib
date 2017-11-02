#!/bin/sh

export TARGET=baremetal

cd utils
./clean.sh
cd ..

rm -f include/limits.h

cd src
./clean.sh
cd ..
