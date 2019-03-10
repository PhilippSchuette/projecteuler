/*
 * A library of utility functions.
 * Part of https://github.com/PhilippSchuette/projecteuler.
 */
// `ParamError' enumerates errors that are related to function
// parameters.
#[derive(Debug)]
pub enum ParamError {
    InputOutOfRange,
}

// Calculates the greatest common divisor of two numbers
// `a' and `b' using Euclid's algorithm.
#[allow(dead_code)]
pub fn gcd(a: i64, b: i64) -> i64 {
    let (mut i, mut j) = (a, b);

    while i != j {
        if i > j {
            i -= j;
        } else {
            j -= i;
        }
    }
    return i;
}

// Returns true if the input is a prime number.
pub fn is_prime(n: i64) -> bool {
    // Handle corner cases, `n' < 1 is not a valid
    // input and even numbers cannot be prime.
    if n <= 1 {
        return false;
    } else if n == 2 {
        return true;
    } else if n % 2 == 0 {
        return false; /* n==2 must be handled first */
    }

    // Determine primality via a O(sqrt(n)) approach. This
    // method is valid because once sqrt(n) is reached, all
    // larger divisors are simply dividends of a previous divisor.
    // In addition, only odd numbers are tested.
    for i in (3..(n as f64).sqrt() as i64 + 1).step_by(2) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

