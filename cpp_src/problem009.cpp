// Project Euler Problem 009 Solution
//
// Problem statement: A Pythagorean triplet is a set of three natural numbers, <var>a</var> Problem statement:lt; <var>b</var> Problem statement:lt; <var>c</var>, for which,<div style="text-align:center;"> <var>a</var>^{2} + <var>b</var>^{2} = <var>c</var>^{2}</div>For example, 3^{2} + 4^{2} = 9 + 16 = 25 = 5^{2}.There exists exactly one Pythagorean triplet for which <var>a</var> + <var>b</var> + <var>c</var> = 1000.<br />Find the product <var>abc</var>.
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/06
// License: MIT (see ../LICENSE.md)

#include "problem009.hpp"
#include <omp.h>
#include <fmt/format.h>

bool is_perfect_square(unsigned n) {
    unsigned sq = sqrt(n);
    return n == sq * sq;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    auto solution = []() -> unsigned {
        for (unsigned a = 2; ; a++) 
            for (unsigned b = 1; b < a; b++) 
                if (double c_sq = a*a + b*b; is_perfect_square(c_sq) and a + b + sqrt(c_sq) == 1000) 
                    return a * b * sqrt(c_sq);
    }();
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
