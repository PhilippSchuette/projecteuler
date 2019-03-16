// Project Euler Problem 012 Solution
//
// Problem statement: The sequence of triangle numbers is generated by adding the natural numbers. So the 7^{th} triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:<p style="text-align:center;">1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...Let us list the factors of the first seven triangle numbers:<blockquote style="font-family:'courier new';"><b> 1</b>: 1<br /><b> 3</b>: 1,3<br /><b> 6</b>: 1,2,3,6<br /><b>10</b>: 1,2,5,10<br /><b>15</b>: 1,3,5,15<br /><b>21</b>: 1,3,7,21<br /><b>28</b>: 1,2,4,7,14,28</blockquote>We can see that 28 is the first triangle number to have over five divisors.What is the value of the first triangle number to have over five hundred divisors?
//
// Solution description:
//
// Author: Tom Praschan
// 2019/03/08
// License: MIT (see ../LICENSE.md)

#include "problem012.hpp"
#include <omp.h>
#include <fmt/format.h>

// Finds the number of divisors of n via bruteforce
unsigned num_divisors_bruteforce(unsigned n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    //Intialize to 2 -> always count 1 and the number itself
    unsigned num_divisors = 2;

    for (unsigned i = 2; i < n / 2 + 1; i++) {
        if (n % i == 0)
            num_divisors++;
    }
    return num_divisors;
}

// Return the nth triangle number using Gauß' formula
unsigned triangle_number(unsigned n) {
    return (n * (n + 1)) / 2;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    unsigned n = 1;
    for (n = 1; num_divisors_bruteforce(triangle_number(n)) <= 500; n++) {}
    auto solution = triangle_number(n);
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif