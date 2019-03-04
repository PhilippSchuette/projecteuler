/* Project Euler Problem 14 Solution
 *
 * Problem statement:
 * The following iterative sequence is defined for the set
 * of positive integers:
 *
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate
 * the following sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and
 * finishing at 1) contains 10 terms. Although it has not
 * been proved yet (Collatz Problem), it is thought that
 * all starting numbers finish at 1. Which starting number,
 * under one million, produces the longest chain? Once the
 * chain starts the terms are allowed to go above one million.
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/04
 * License: MIT (see ../LICENSE.md)
 */
// Returns the length of a Collatz sequence starting at
// `start'. See the problem statement for details.
pub fn collatz_len(start: i64) -> i64 {
    let mut length: i64 = 1; /* every seq has at least 1 item */
    let mut current = start;

    loop {
        // if the sequence reaches 1, return
        if current == 1 {
            return length;
        }

        // otherwise, calculate the next member and
        // increment the length counter
        if current % 2 == 0 {
            current /= 2;
        } else {
            current = 3 * current + 1;
        }
        length += 1;
    }
}

// Returns the starting number less than `n' which
// produces the longest Collatz sequence.
pub fn find_longest_collatz(n: i64) -> i64 {
    let mut longest_starting: i64 = 0;
    let mut longest: i64 = 0;

    for i in 1..n {
        let length = collatz_len(i);
        if length > longest {
            longest = length;
            longest_starting = i;
        }
    }
    return longest_starting;
}
