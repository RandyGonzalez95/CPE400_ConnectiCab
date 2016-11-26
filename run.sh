#!/bin/bash
rm -r build
mkdir build
cd build
cp ../makefile .
make
./ConnectiCab
	
