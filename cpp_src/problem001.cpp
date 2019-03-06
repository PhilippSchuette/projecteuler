// Project Euler Problem 001 Solution
//
// Problem statement: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.Find the sum of all the multiples of 3 or 5 below 1000.
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/05
// License: MIT (see ../LICENSE.md)

#include "problem001.hpp"
#include <omp.h>
#include <fmt/format.h>
#include <numeric>

// Returns all the multiples of 3 or 5 below n
std::vector<int> multiples35_below(unsigned n) {
    if (n <= 3) 
        return {};
    if (n <= 5)
        return {3};
    std::vector<int> mult = {3, 5};
    for (unsigned i = 6; i < n; i++) {
        if (i % 3 == 0 or i % 5 == 0) {
            mult.push_back(i);
        }
    }
    return mult;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    auto mult = multiples35_below(1000);
    auto solution = std::accumulate(mult.begin(), mult.end(), 0);
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
