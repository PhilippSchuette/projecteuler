/* Project Euler Problem 21 Solution
 *
 * Problem statement:
 * Let d(n) be defined as the sum of proper divisors of n
 * (numbers less than n which divide evenly into n). If
 * d(a) = b and d(b) = a, where a ≠ b, then a and b are an
 * amicable pair and each of a and b are called amicable
 * numbers. For example, the proper divisors of 220 are
 * 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore
 * d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71
 * and 142; so d(284) = 220. Evaluate the sum of all the
 * amicable numbers under 10000.
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/15
 * License: MIT (see ../LICENSE.md)
 */
pub fn divisor_sum(num: i64) -> i64 {
    let mut sum: i64 = 0;
    let mut divisors = vec![1];

    // push divisors of `num' onto vector
    for i in 2..(num / 2 + 2) {
        if num % i == 0 {
            divisors.push(i);
        }
    }

    // calculate sum over all vector elements
    for e in divisors.iter() {
        sum += e;
    }
    sum
}

pub fn is_amicable(num: i64) -> bool {
    let d_sum = divisor_sum(num);

    // exclude perfect numbers for which the sum of
    // their divisors equals themselves (e.g. 6,
    // because 1 + 2 + 3 = 6 again).
    if divisor_sum(d_sum) == num && num != d_sum {
        return true;
    }
    false
}

pub fn solve(n: i64) -> i64 {
    let mut sum: i64 = 0;
    for i in 1..n {
        if is_amicable(i) {
            sum += i;
        }
    }
    sum
}
