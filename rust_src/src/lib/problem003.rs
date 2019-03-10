/* Project Euler Problem 3 Solution
 *
 * Problem statement:
 * The prime factors of 13195 are 5, 7, 13 and 29. What
 * is the largest prime factor of the number 600851475143?
 *
 * Solution description:
 * --
 *
 * Author: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
use crate::utils;

pub fn largest_prime_factor(n: i64) -> i64 {
    let mut divisor = 2;
    let mut current;

    loop {
        // calculate number to test
        if n % divisor == 0 {
            current = n / divisor;
        } else {
            divisor += 1; /* increment divisor once more */
            if divisor > n {
                return -1; /* no prime factor found */
            }
            continue; /* continue to next iteration */
        }

        // test primality and potentially return
        if utils::is_prime(current) {
            return current;
        }
        divisor += 1; /* increment for next iteration */
    }
}
