#!/bin/sh
# Determine coverage using gcov.

# problem 1
./p1
./p1 1000 --silent
./p1 1000 1000 --silent
./p1 not_valid --silent
gcov p1

# problem 2
./p2
gcov p2

# problem 3
./p3 --silent
./p3 slow
gcov p3

# problem 24
./p24
gcov p24
