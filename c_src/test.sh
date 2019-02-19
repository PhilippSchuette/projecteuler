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
