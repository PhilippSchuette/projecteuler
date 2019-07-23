#pragma once

template <int n>
constexpr int fib() {
    static_assert(n > 2);
    return fib<n-1>() + fib<n-2>();
}

template <>
constexpr int fib<1>() {
    return 1;
}

template <>
constexpr int fib<2>() {
    return 2;
}

template <int fibIndex = 1, int sum = 0>
constexpr int fibSum() {
    if constexpr (constexpr auto currFib = fib<fibIndex>(); currFib > 4000000) {
        return sum;
    } else {
        return fibSum<fibIndex+1, sum + currFib * ((currFib + 1) % 2) >();
    }
}

