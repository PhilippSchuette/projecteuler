/*
 * A library of utility functions.
 * Part of https://github.com/PhilippSchuette/projecteuler.
 */
extern crate num_bigint;

use num_bigint::BigUint;
use std::convert::From;

// `ParamError' enumerates errors that are related to function
// parameters.
#[derive(Debug, PartialEq)] /* #no_code */
pub enum ParamError {
    InputOutOfRange,
}

// Calculates the greatest common divisor of two numbers `a' and
// `b' using Euclid's algorithm.
#[allow(dead_code)]
pub fn gcd(a: i64, b: i64) -> i64 {
    let (mut i, mut j) = (a, b);

    while i != j {
        if i > j {
            i -= j;
        } else {
            j -= i;
        }
    }
    return i;
}

// Returns true if the input is a prime number.
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

    // Determine primality via a O(sqrt(n)) approach. This
    // method is valid because once sqrt(n) is reached, all
    // larger divisors are simply dividends of a previous divisor.
    // In addition, only odd numbers are tested.
    for i in (3..(n as f64).sqrt() as i64 + 1).step_by(2) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

// Returns the sum of all digits in a `String' representation of
// a float, e.g. fn(336.0) -> 12.
pub fn sum_of_digits(num: String) -> i64 {
    let mut sum = 0;

    for b in num.chars() {
        if b != '.' {
            sum += b.to_digit(10).unwrap() as i64;
        }
    }
    sum
}

// Returns n!. The calculation is done recursively on `BigUint'.
pub fn factorial(n: BigUint) -> BigUint {
    let num: BigUint = BigUint::from(1 as usize);
    let num_next: BigUint = BigUint::from(2 as usize);

    if n < num_next {
        num.clone()
    } else {
        let previous = factorial(n.clone() - num);
        n * previous
    }
}

// A generic bubble sort implementation. The input vector is
// sorted in-place.
#[allow(dead_code)]
pub fn bubble_sort<T: PartialOrd + Clone>(vec: &mut Vec<T>) {
    for i in 0..(vec.len() - 1) {
        for j in 0..(vec.len() - 1 - i) {
            if vec[j] > vec[j + 1] {
                // swap elements
                let tmp = vec[j].clone();
                vec[j] = vec[j + 1].clone();
                vec[j + 1] = tmp;
            }
        }
    }
}

// A generic insertion sort implementation. The input vector is
// sorted in-place.
pub fn insertion_sort<T: PartialOrd + Clone>(vec: &mut Vec<T>) {
    for i in 1..vec.len() {
        // insert i'th element into the sorted [0..i-1] part of `vec'
        'insert_loop: for j in 0..i {
            if vec[j] > vec[i] {
                vec.insert(j, vec[i].clone()); /* shifts j right, inserts i */
                vec.remove(i+1); /* i'th element is now i+1 */
                break 'insert_loop; /* move on to next element */
            }
        }
    }
}
