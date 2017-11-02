#!/bin/sh

rm -f puts.o
rm -f stdout.o

cd ${TARGET}
./clean.sh
cd ..
