// Project Euler Problem 021 Solution
//
// Problem statement: Let d(<i>n</i>) be defined as the sum of proper divisors of <i>n</i> (numbers less than <i>n</i> which divide evenly into <i>n</i>).<br />If d(<i>a</i>) = <i>b</i> and d(<i>b</i>) = <i>a</i>, where <i>a</i> ≠ <i>b</i>, then <i>a</i> and <i>b</i> are an amicable pair and each of <i>a</i> and <i>b</i> are called amicable numbers.For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.Evaluate the sum of all the amicable numbers under 10000.
//
// Solution description: Bruteforce 
//
// Author: Tom Praschan
// 2019/03/19
// License: MIT (see ../LICENSE.md)

#include "problem021.hpp"
#include "prime_utils.hpp"
#include <omp.h>
#include <fmt/format.h>

unsigned sum_of_divisors(unsigned n) {
    unsigned sum = 1;
    for (unsigned i = 2; i <= (unsigned) sqrt(n); i++)
        if (n % i == 0) {
            sum += i + n / i;
        }
    return sum;
}

std::pair<bool, int> isAmicableNumber(unsigned n) {
    if (size_t sum = sum_of_divisors(n); sum_of_divisors(sum) == n) {
        return {sum != n, sum};
    } else {
        return {false, sum};
    }
}


#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();
    unsigned solution = 0;
    for (unsigned n = 1; n < 10000; n++) {
        auto [amicable, sum] = isAmicableNumber(n);
        if (amicable)
            solution += n;
    }
    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
