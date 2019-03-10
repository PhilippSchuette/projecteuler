// Project Euler Problem 014 Solution
//
// Problem statement: The following iterative sequence is defined for the set of positive integers:<p style="margin-left:50px;"><var>n</var> → <var>n</var>/2 (<var>n</var> is even)<br /><var>n</var> → 3<var>n</var> + 1 (<var>n</var> is odd)Using the rule above and starting with 13, we generate the following sequence:<div style="text-align:center;">13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1</div>It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.Which starting number, under one million, produces the longest chain?<p class="note"><b>NOTE:</b> Once the chain starts the terms are allowed to go above one million.
//
// Solution description: Bruteforce
//
// Author: Tom Praschan
// 2019/03/10
// License: MIT (see ../LICENSE.md)

#include "problem014.hpp"
#include <omp.h>
#include <fmt/format.h>

unsigned collatz_len(unsigned n) {
    unsigned len;
    for (len = 1; n != 1; len++){
        n = n % 2 == 0 ? n / 2 : 3*n + 1;
    }
    return len;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    unsigned max = 0, solution;
    for (unsigned i = 1; i < 1000000; i++) {
        if (auto len = collatz_len(i); len > max) {
            max = len;
            solution = i;
        }
    }
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
