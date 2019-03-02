/* Project Euler Problem 6 Solution
 *
 * Problem statement:
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385. The square of the sum of the
 * first ten natural numbers is (1 + 2 + ... + 10)^2 = 55^2 = 3025.
 * Hence the difference between the sum of the squares of the
 * first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first
 * one hundred natural numbers and the square of the sum.
 *
 * Solution description:
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
// Calculate the sum of squares in range 1..target.
pub fn sum_of_squares(target: i32) -> i32 {
    let mut sum = 0;

    for i in 1..target + 1 {
        sum += i32::pow(i, 2);
    }
    return sum;
}

// Calculate the square of sums in range 1..target.
pub fn square_of_sums(target: i32) -> i32 {
    let mut sum = 0;

    for i in 1..target + 1 {
        sum += i;
    }
    return i32::pow(sum, 2);
} // #no_code

// Return the difference between the values that were
// calculated based upon the targets. Basically a
// wrapper to return the problem solution without
// intermediate steps being exposed to `main.rs'.
pub fn solve(target1: i32, target2: i32) -> i32 {
    return square_of_sums(target2) - sum_of_squares(target1);
}
