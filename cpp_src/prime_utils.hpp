#pragma once

#include <stddef.h>
#include <vector>

bool is_prime(size_t n);

//Vector containing natural numbers
typedef std::vector<size_t> nvec;

// Given a natural number n, this method return it's prime 
// factorization n = p1^e1 * p2^e2 * ...
// The return value is a vector containing the prime factors p
// and a vector containing their exponents e
const std::pair<nvec, nvec> prime_factors(size_t n);
