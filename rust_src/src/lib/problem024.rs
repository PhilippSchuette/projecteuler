/* Project Euler Problem 24 Solution
 *
 * Problem statement:
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 * 012   021   102   120   201   210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/04/21
 * License: MIT (see ../LICENSE.md)
 */
#[derive(Debug)]
struct LexPermutation {
    digits: Vec<u8>,     /* ordered digits of current permutation */
    current_permut: u64, /* current permutation */
    limit: u64,          /* iterates up to this value */
}

impl LexPermutation {
    fn new(digits: Vec<u8>, limit: u64) -> LexPermutation {
        LexPermutation { digits,
                         current_permut: 1, /* because of initial seq */
                         limit }
    }

    // swap elements `i' and `j' of `LexPermutation.digits'
    fn swap(&mut self, i: usize, j: usize) {
        let tmp = self.digits[i];
        self.digits[i] = self.digits[j];
        self.digits[j] = tmp;
    }

    // reverse `LexPermutation.digits' from `i' to the end
    fn reverse(&mut self, idx: usize) {
        let half: usize = (idx + (self.digits.len())) / 2;
        let mut end = self.digits.len() - 1;

        for i in idx..half {
            self.swap(i, end);
            end -= 1;
        }
    }
}

impl Iterator for LexPermutation {
    type Item = Vec<u8>;

    // if there are less than `self.limit' permutations,
    // the iterator's behavior is undefined
    fn next(&mut self) -> Option<Vec<u8>> {
        // check boundary condition and increment counter
        if self.current_permut == self.limit {
            return None;
        }
        self.current_permut += 1;

        // permutate elements in lexicographic order
        // example: 012 021 102 120 201 210
        for i in (0..(self.digits.len() - 1)).rev() {
            // find the first right-most character which is
            // smaller than the one left to it (the pivot)
            if self.digits[i] < self.digits[i + 1] {
                let mut smallest = max_in_vec(&self.digits);
                let mut smallest_idx = 0;

                // find the first element to the right of the pivot
                // that is larger than the pivot but the smallest of
                // the sequence between pivot and sequence end
                for j in (i + 1)..self.digits.len() {
                    if (self.digits[j] <= smallest)
                       && (self.digits[j] > self.digits[i])
                    {
                        smallest = self.digits[j];
                        smallest_idx = j;
                    }
                }

                // swap first, then reverse the sequence from the first
                // element after the pivot to the end
                self.swap(i, smallest_idx);
                self.reverse(i + 1);
                break; /* done for this iteration */
            }
        }
        Some(self.digits.clone())
    }
}

pub fn solve() -> i64 {
    let permutations = LexPermutation::new((0..10).collect(), 1_000_000);
    let result = permutations.last().expect("Iterator failed");
    get_result(&result)
}

pub fn max_in_vec<T>(vec: &Vec<T>) -> T
    where T: PartialOrd + Clone
{
    let mut max: T = vec[0].clone();
    for i in 1..vec.len() {
        if vec[i] > max {
            max = vec[i].clone();
        }
    }
    max
}

pub fn get_result(vec: &Vec<u8>) -> i64 {
    let mut res = String::from("");
    for i in 0..vec.len() {
        res = format!("{}{}", res, vec[i]);
    }
    res.parse().unwrap()
}
