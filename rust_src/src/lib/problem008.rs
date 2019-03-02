/* Project Euler Problem 8 Solution
 *
 * Problem statement:
 * The four adjacent digits in the 1000-digit number in
 * `../inputs/problem008.in' that have the greatest product
 * are 9 × 9 × 8 × 9 = 5832. Find the thirteen adjacent digits
 * in the 1000-digit number that have the greatest product.
 * What is the value of this product?
 *
 * Solution description:
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
use std::fs;

pub fn parse_data(path: String) -> String {
    let data: String;

    // open file and read content
    let file = fs::read_to_string(&path);
    if file.is_ok() {
        data = file.unwrap();
    } else {
        panic!("err: {} does not exist", path);
    }

    // remove line breaks and return string
    let mut data_str = String::from("");
    for c in data.chars() {
        if c != '\n' {
            data_str.push(c);
        }
    }
    return data_str;
} // #no_code

pub fn adjacent_digits(s: String) -> i64 {
    let num_digits = 13;
    let mut prod: i64 = 0;

    for i in 0..(s.len() + 1 - num_digits) {
        // Input string must be at least `num_digits' long,
        // otherwise the following unwrap panics.
        let ss = s.get(i..(i + num_digits)).unwrap();
        let mut new_prod: i64 = 1;
        for c in ss.chars() {
            // Don't do input validation here because
            // the string provided to this function is
            // expected to be well-formed anyways.
            new_prod *= c.to_digit(10).unwrap() as i64;
        }
        if new_prod > prod {
            prod = new_prod;
        }
    }
    return prod;
} // #no_code
