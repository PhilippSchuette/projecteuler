// Project Euler Problem 006 Solution
//
// Problem statement: The sum of the squares of the first ten natural numbers is,<div style="text-align:center;">1^{2} + 2^{2} + ... + 10^{2} = 385</div>The square of the sum of the first ten natural numbers is,<div style="text-align:center;">(1 + 2 + ... + 10)^{2} = 55^{2} = 3025</div>Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/06
// License: MIT (see ../LICENSE.md)

#include "problem006.hpp"
#include <omp.h>
#include <fmt/format.h>

unsigned sum_of_squares(unsigned max) {
    unsigned sum = 0;
    for (unsigned i = 1; i <= max; i++) {
        sum += i * i;
    }
    return sum;
}

// Uses Gauss' formula to compute the sum
unsigned square_of_sum(unsigned max) {
    return pow((max * (max + 1)), 2) / 4;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    int solution = square_of_sum(100) - sum_of_squares(100);
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
