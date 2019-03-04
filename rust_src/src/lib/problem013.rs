/* Project Euler Problem 13 Solution
 *
 * Problem statement:
 * Work out the first ten digits of the sum of the following one-
 * hundred 50-digit numbers (see inputs/problem013.in).
 *
 * Solution description:
 * Since Python ints use arbitrary precision we can just sum up all
 * the numbers without worrying about integer overflow. When arbitrary
 * precision is no available, one would probably have to use long
 * division.
 *
 * Author: Daniel Schuette
 * Date: 2019/03/03
 * License: MIT (see ../LICENSE.md)
 */
use std::fs;

extern crate num_bigint as bigint;
extern crate num_traits;

use bigint::BigInt;

// Returns the first 10 digits of the sum of large
// ints from the input file at `path'.
pub fn sum_big_ints(path: &str) -> String {
    let mut sum: BigInt = num_traits::Zero::zero();
    let data_str: String;

    // read data from file
    let file = fs::read_to_string(path);
    if file.is_ok() {
        data_str = file.unwrap();
    } else {
        panic!("err: {} does not exist", path);
    }

    // split data at new line and add up
    for line in data_str.split("\n") {
        let big = BigInt::parse_bytes(line.as_bytes(), 10);
        if big.is_some() {
            let num = big.unwrap();
            sum = sum + num;
        }
    }

    // return the first 10 digits as a str
    let digits_str = sum.to_string();
    return digits_str;
}
