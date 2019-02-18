#pragma once

#include <functional>

bool is_prime(size_t n);

size_t prime_sum(std::function<bool(size_t)> prime_test, size_t max);
