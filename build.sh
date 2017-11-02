#!/bin/sh

export TARGET=baremetal

cd utils
./build.sh
cd ..

utils/generate-limits --output include/limits.h

cd src
./build.sh
cd ..
