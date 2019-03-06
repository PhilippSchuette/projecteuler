// Project Euler Problem 004 Solution
//
// Problem statement: A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.Find the largest palindrome made from the product of two 3-digit numbers.
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/06
// License: MIT (see ../LICENSE.md)

#include "problem004.hpp"
#include <omp.h>
#include <fmt/format.h>
#include <string>

bool is_palindrome(unsigned n) {
    auto s = std::to_string(n);
    auto rev = s; std::reverse(rev.begin(), rev.end());
    return s == rev;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    unsigned max = 0;
    for (unsigned i = 100; i < 1000; i++) {
        for(unsigned j = 0; j < 1000; j++) {
            if (auto prod = i * j; prod > max and is_palindrome(prod)) {
                max = prod;
            }
        }
    }
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", max);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
