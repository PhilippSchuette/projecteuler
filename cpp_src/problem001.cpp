// Project Euler Problem 001 Solution
//
// Problem statement: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.Find the sum of all the multiples of 3 or 5 below 1000.
//
// Solution description: Compile time solution
//
// Author: Tom Praschan
// 2019/03/05
// License: MIT (see ../LICENSE.md)

#include "problem001.hpp"
#include <omp.h>
#include <fmt/format.h>
#include <numeric>

#ifndef TESTING
int main(int argc, char **argv) {
    fmt::print("Solution: {} \n", sum_multiples35_below<1000>());
}
#endif
