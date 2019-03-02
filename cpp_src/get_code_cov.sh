#!/usr/bin/env bash

# Run all tests 
./tests.out
# Record coverage with lcov
lcov --directory CMakeFiles/tests.dir --capture --output-file coverage.info
# Get rid of library headers
lcov --remove coverage.info '/usr/*' '*/include/Catch2/*' --output-file coverage.info

# Output data for debugging
lcov --list coverage.info


