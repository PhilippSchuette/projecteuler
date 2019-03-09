/*
 * A library of utility functions.
 * Part of https://github.com/PhilippSchuette/projecteuler.
 */
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
