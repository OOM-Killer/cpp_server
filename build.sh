#!/bin/bash

make clean &&
make -j 16 &&
./server localhost 12345 12
