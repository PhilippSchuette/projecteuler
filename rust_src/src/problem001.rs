/* Project Euler Problem 1 Solution
 *
 * Problem statement:
 * If we list all the natural numbers below 10 that are multiples
 * of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
pub fn sum_multiples(target: i32) -> i64 {
    let (a, b) = (3, 5);
    let mut sum: i64 = 0;

    for i in 1..target {
        if (i % a == 0) || (i % b == 0) {
            sum += i as i64;
        }
    }
    return sum;
}
