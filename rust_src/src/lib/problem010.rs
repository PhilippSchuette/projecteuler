/* Project Euler Problem 10 Solution
 *
 * Problem statement:
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 *
 * Solution description:
 * --
 *
 * Author: Daniel Schuette
 * Date: 2019/03/02
 * License: MIT (see ../LICENSE.md)
 */
use crate::lib;

// Returns the sum of all primes below `n'.
pub fn sum_primes(n: i64) -> i64 {
    let mut sum: i64 = 0;

    for i in (1..n).step_by(2) {
        if lib::problem007::is_prime(i) {
            sum  += i;
        }
    }
    return sum;
}
