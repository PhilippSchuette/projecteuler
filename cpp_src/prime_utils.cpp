#include "prime_utils.hpp"
#include <cmath>

// This function returns a boolean value indicating whether the input "n" is a primer number or not.
bool is_prime(size_t n) {
    if (n == 0 or n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (size_t i = 3; i <= (size_t) sqrt((double) n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

const std::pair<nvec, nvec> prime_factors(size_t n) {
    if (n == 2) return {std::make_pair(nvec({2}), nvec({1}))};
    if (is_prime(n)) return {std::make_pair(nvec({n}), nvec({1}))};

    nvec prime_factors, exponents; 

    const int max = n;

    //Special case: n is even
    if (n % 2 == 0) {
        size_t p = 0;
        do {
            n /= 2;
            p++;
        } while (n % 2 == 0);
        prime_factors.push_back(2);
        exponents.push_back(p);
    }
    for (size_t i = 3; i <= n; i+=2) {
        if (n % i == 0 && is_prime(i)) {
            size_t p = 0;
            do { 
                n /= i;
                p++;
            } while (n % i == 0);
            prime_factors.push_back(i);
            exponents.push_back(p);
        }
    }
    return std::make_pair(prime_factors, exponents);
}
