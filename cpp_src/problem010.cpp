// Project Euler Problem 10 Solution
//
// Problem statement:
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// Solution description:
// --
//
// Author: Tom Praschan
// Date: 2019/02/10
// License: MIT (see ../LICENSE.md)

#include "fmt/format.h"
#include "problem010.hpp"
#include "prime_utils.hpp"
#include <cmath>
#include <omp.h>

// Calculates the sum of all primes below max
// The loop is parallelized using OpenMP
size_t prime_sum(std::function<bool(size_t)> prime_test, size_t max) {
    size_t sum = 2;
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 3; i < max; i+=2) {
        if (prime_test(i)) {
            sum += i;
        }
    }
    return sum;
}

#ifndef TESTING
int main(int argc, char **argv) {
    // Read upper bound from command line arguments
    size_t max = argc > 1 ? atoi(argv[1]) : 2e6;

    auto start = omp_get_wtime();
    auto solution = prime_sum(is_prime, max);
    auto end = omp_get_wtime();

    fmt::print("Solution: {}\nElapsed time: {}s \n", solution, end-start);
}
#endif
