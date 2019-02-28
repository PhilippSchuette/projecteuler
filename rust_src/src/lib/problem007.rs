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
// Returns true if the input is a prime number. Might
// be used as a helper function in other places, so
// make sure to not break compatibility by changing
// the function signature.
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

    // Determine primality via a O(n/2) approach (only odd
    // numbers are tested, too).
    for i in (3..(n / 2) + 1).step_by(2) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

pub fn nth_prime(target: i64) -> i64 {
    let mut prime_count: i64 = 1; /* 2 is already counted in */
    let mut current_num: i64 = 3;

    loop {
        if is_prime(current_num) {
            prime_count += 1;
            if prime_count == target {
                return current_num;
            }
        }
        current_num += 2;
    }
}
