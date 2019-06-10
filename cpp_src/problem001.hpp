#pragma once

// Returns the sum all the multiples of 3 or 5 below n
// If n is known at compile time, this function will be 
// computed at compile time as well
template <unsigned max, unsigned sum = 0>
constexpr unsigned sum_multiples35_below() {
    constexpr auto n = max - 1;
    constexpr auto nextSum = []() -> unsigned {
        if (n % 3 == 0 or n % 5 == 0) {
            return sum + n;
        }
        return sum;
    };
    if constexpr (max == 6) {
        return 8 + sum;
    } else {
        return sum_multiples35_below<max - 1, nextSum()>(); 
    }
}
