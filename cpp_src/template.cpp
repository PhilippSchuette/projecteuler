// template.cpp demonstrates how to structure the problem
// Project Euler Problem X Solution
//
// Problem statement:
//
// Solution description:
//
// Author: <author_name>
// Date: 2018/../..
// License: MIT (see ../LICENSE.md)

#include "header.hpp"
#include <omp.h>
#include <fmt/format.h>

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    // Solution goes here!
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
