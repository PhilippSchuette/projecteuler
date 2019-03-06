// Project Euler Problem 005 Solution
//
// Problem statement: 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.What is the smallest positive number that is <dfn title="divisible with no remainder">evenly divisible</dfn> by all of the numbers from 1 to 20?
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/06
// License: MIT (see ../LICENSE.md)

#include "problem005.hpp"
#include <omp.h>
#include <fmt/format.h>

unsigned smallest_evenly_divisible(unsigned target) {
    unsigned smallest = 2 * target;
    while (true) {
        for (unsigned i = target; i > 1; i--) {
            if (smallest % i != 0) {
                break;
            }
            if (i == 2) {
                return smallest;
            }
        }
        smallest += target;
    }
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    auto solution = smallest_evenly_divisible(20);
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
