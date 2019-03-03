// Project Euler Problem 007 Solution
//
// Problem statement: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.What is the 10 001st prime number?
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/03
// License: MIT (see ../LICENSE.md)

#include <omp.h>
#include <fmt/format.h>
#include "prime_utils.hpp"

//Computes the nth prime number
size_t nth_prime(size_t n) {
    if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 3;
    }
    size_t index = 2, p = 3;
    while (index != n) {
        p += 2;
        if (is_prime(p)) {
            index++;
        }
    }
    return p;
}

#ifndef TESTING
int main(int argc, char **argv) {
   auto start = omp_get_wtime();
   auto solution = nth_prime(10001);
   auto end = omp_get_wtime();

   fmt::print("Solution: {} \n", solution);
   fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
