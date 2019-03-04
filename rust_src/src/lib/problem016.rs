/* Project Euler Problem 16 Solution
 *
 * Problem statement:
 * 2^15 = 32768 and the sum of its digits is
 * 3 + 2 + 7 + 6 + 8 = 26. What is the sum of
 * the digits of the number 2^1000?
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/04
 * License: MIT (see ../LICENSE.md)
 */
pub fn sum_of_digits(base: f64, power: f64) -> i64 {
    let mut res: i64 = 0;

    // `powf' works well for large floating point numbers
    let num: f64 = base.powf(power);

    // using the `format' macro ensures that the resulting
    // string has the highest possible precision
    let num_str = format!("{:.1}", num);

    // iterate over the string representation and sum up
    // the individual digits
    for b in num_str.chars() {
        if b != '.' {
            res += b.to_digit(10).unwrap() as i64;
        }
    }
    return res;
}
