/* Project Euler Problem 11 Solution
 *
 * Problem statement:
 * In the 20×20 grid below, four numbers along a diagonal line
 * have been marked in red (see `inputs/problem011.in').
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the
 * same direction (up, down, left, right, or diagonally) in the
 * 20×20 grid?
 *
 * Solution description:
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2019/03/03
 * License: MIT (see ../LICENSE.md)
 */
use std::fs;

pub fn parse_matrix(path: &str) -> Vec<Vec<i64>> {
    let data_str: String;
    let mut data: Vec<Vec<i64>> = vec![];

    // read data from file
    let file = fs::read_to_string(path);
    if file.is_ok() {
        data_str = file.unwrap();
    } else {
        panic!("err: {} does not exist", path);
    }

    // read data into matrix
    for line in data_str.split("\n") {
        let mut v: Vec<i64> = vec![];
        for num in line.split(" ") {
            let p = num.parse::<i64>();
            let d: i64;
            if p.is_ok() {
                d = p.unwrap();
                v.push(d);
            } else {
                return data; /* reached end of data str */
            }
        }
        data.push(v);
    }
    return data;
}

pub fn greatest_product(matrix: Vec<Vec<i64>>) -> i64 {
    let mut product: i64 = 0;
    let adj_digits = 4; /* number of adjacent digits to multiply */

    // calculate product from left to right
    for r_idx in 0..(matrix.len()) {
        for c_idx in 0..(matrix[0].len() - adj_digits) {
            let p = mult_over_slice(&(matrix[r_idx][c_idx..(c_idx + adj_digits)]));
            if p > product {
                product = p;
            }
        }
    }

    // calculate product from top to bottom
    for r_idx in 0..(matrix.len() - adj_digits) {
        for c_idx in 0..(matrix[0].len()) {
            let mut v = vec![];
            for i in 0..adj_digits {
                v.push(matrix[r_idx + i][c_idx]);
            }

            let p = mult_over_slice(&v[..]);
            if p > product {
                product = p;
            }
        }
    }

    // calculate product from top left to bottom right
    for r_idx in 0..(matrix.len() - adj_digits) {
        for c_idx in 0..(matrix[0].len() - adj_digits) {
            let mut v = vec![];
            for i in 0..adj_digits {
                v.push(matrix[r_idx + i][c_idx + i]);
            }

            let p = mult_over_slice(&v[..]);
            if p > product {
                product = p;
            }
        }
    }

    // calculate product from top right to bottom left
    for r_idx in 0..(matrix.len() - adj_digits) {
        for c_idx in ((adj_digits - 1)..matrix[0].len()).rev() {
            let mut v = vec![];
            for i in 0..adj_digits {
                v.push(matrix[r_idx + i][c_idx - i]);
            }

            let p = mult_over_slice(&v[..]);
            if p > product {
                product = p;
            }
        }
    }

    return product;
}

pub fn mult_over_slice(s: &[i64]) -> i64 {
    let mut p: i64 = 1;

    for i in s {
        p *= i;
    }
    return p;
}
