#!/bin/bash
if [ -d "build" ]; then
	rm -r build
fi
mkdir build
cd build
cp ../makefile .
make
./ConnectiCab
