/* Project Euler Problem 20 Solution
 *
 * Problem statement:
 * n! means n × (n − 1) × ... × 3 × 2 × 1. For example,
 * 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum
 * of the digits in the number 10! is
 * 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27. Find the sum of the
 * digits in the number 100!
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/15
 * License: MIT (see ../LICENSE.md)
 */
extern crate num_bigint;
use crate::utils;

pub fn solve(n: usize) -> i64 {
    let big = num_bigint::BigUint::from(n);
    let fac = utils::factorial(big);
    utils::sum_of_digits(fac.to_str_radix(10))
}
