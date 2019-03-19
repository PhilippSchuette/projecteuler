// Project Euler Problem 003 Solution
//
// Problem statement: The prime factors of 13195 are 5, 7, 13 and 29.What is the largest prime factor of the number 600851475143 ?
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/19
// License: MIT (see ../LICENSE.md)

#include "problem003.hpp"
#include "prime_utils.hpp"
#include <omp.h>
#include <fmt/format.h>

size_t largest_prime_factor(size_t n) {
    auto &[factors, exponents] = prime_factors(n);
    return factors.back();
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    auto solution = largest_prime_factor(600851475143);
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
