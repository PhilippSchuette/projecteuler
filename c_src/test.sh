#!/bin/sh
# determine test coverage using gcov

# problem 1
./p1
./p1 1000
./p1 1000 1000
./p1 not_valid
gcov problem001.c

# problem 2
./p2
gcov problem002.c
