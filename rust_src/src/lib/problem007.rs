/* Project Euler Problem 7 Solution
 *
 * Problem statement:
 * By listing the first six prime numbers: 2, 3, 5, 7, 11,
 * and 13, we can see that the 6th prime is 13. What is the
 * 10 001st prime number?
 *
 * Solution description:
 * This script uses a brute-force approach to determine the
 * n'th prime number. This is a slow approach which should
 * be improved in the future!
 *
 * Author: Daniel Schuette
 * Date: 2018/02/27
 * License: MIT (see ../LICENSE.md)
 */
use crate::utils;

// Returns the n'th prime number.
pub fn nth_prime(n: i64) -> i64 {
    let mut prime_count: i64 = 1; /* 2 is already counted in */
    let mut current_num: i64 = 3;

    loop {
        if utils::is_prime(current_num) {
            prime_count += 1;
            if prime_count == n {
                return current_num;
            }
        }
        current_num += 2;
    }
}
