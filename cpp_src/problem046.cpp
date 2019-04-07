// Problem statement: It was proposed by Christian Goldbach that every odd
// composite number can be written as the sum of a prime and twice a square.<p
// style="margin-left:10px;">9 = 7 + 2×1^{2}<br />15 = 7 + 2×2^{2}<br />21 = 3
// + 2×3^{2}<br />25 = 7 + 2×3^{2}<br />27 = 19 + 2×2^{2}<br />33 = 31 +
// 2×1^{2}It turns out that the conjecture was false.What is the smallest odd
// composite that cannot be written as the sum of a prime and twice a square?
//
// Solution description: Bruteforce
//
// Author: Tom Praschan
// 2019/04/07
// License: MIT (see ../LICENSE.md)

#include "problem046.hpp"
#include <omp.h>
#include <fmt/format.h>
#include "prime_utils.hpp"

bool violates_goldbach(size_t n, const std::vector<size_t> &primes) {
    for (auto p : primes) {
        for (unsigned s = 0; s < sqrt(n / 2.0); s++) {
            if (n == p + 2 * s * s) {
                return false;
            }
        }
    }
    return true;
}

#ifndef TESTING
int main(int argc, char **argv) {
    auto start = omp_get_wtime();

    size_t solution;
    std::vector<size_t> primes = {2};
    for (size_t n = 3; ; n+=2) {

        if (is_prime(n)) {
            primes.emplace_back(n);
        } else {
            if (violates_goldbach(n, primes)) {
                solution = n;
                break;
            }
        }
    }

    auto end = omp_get_wtime();

    fmt::print("Solution: {} \n", solution);
    fmt::print("Elapsed time: {}s \n", end - start);
}
#endif
