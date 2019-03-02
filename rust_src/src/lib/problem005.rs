/* Project Euler Problem 5 Solution
 *
 * Problem statement:
 * 2520 is the smallest number that can be divided by each of
 * the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible
 * by all of the numbers from 1 to 20?
 *
 * Solution description:
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
pub fn evenly_divisible(target: i32) -> i32 {
    let mut current = 0;
    let mut divisible: bool;

    // If there is no solution, this algorithm
    // does not stop.
    loop {
        divisible = true;
        current += target;
        for i in 1..target {
            if current % i != 0 {
                divisible = false;
                continue;
            }
        }
        if divisible {
            return current;
        }
    }
} // #no_code
