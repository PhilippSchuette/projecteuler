/* Project Euler Problem 18 Solution
 *
 * Problem statement:
 * By starting at the top of the triangle below and moving
 * to adjacent numbers on the row below, the maximum total
 * from top to bottom is 23.
 *                   3
 *                  7 4
 *                 2 4 6
 *                8 5 9 3
 * That is, 3 + 7 + 4 + 9 = 23. Find the maximum total from
 * top to bottom of the triangle in `inputs/problem018.in'.
 *
 * NOTE: As there are only 16384 routes, it is possible to solve
 * this problem by trying every route. However, Problem 67, is the
 * same challenge with a triangle containing one-hundred rows; it
 * cannot be solved by brute force, and requires a clever method!
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/09
 * License: MIT (see ../LICENSE.md)
 */
use std::fs;

// Returns the largest sum of numbers in the triangle located
// at `path'. See the problem statement above for additional
// information.
pub fn find_triangle_sum(path: &str) -> i64 {
    let file = fs::read_to_string(path).expect("Cannot read file");
    let mut data: Vec<Vec<i64>> = vec![];

    // read data from file into vector
    for line in file.split('\n') {
        let mut item: Vec<i64> = vec![];
        for num in line.split(' ') {
            if let Ok(parsed) = num.parse() {
                item.push(parsed);
            } else {
                continue;
            }
        }
        if !item.is_empty() {
            data.push(item);
        }
    }

    // Traverse triangle bottom-up and calculate sums. The
    // approach calculates new rows based on the sums from
    // the previous row to get to the maximum sum in O(n)
    // time (where n is the number of items in the triangle).
    let mut last_sums: Vec<i64> = data[data.len() - 1].clone();
    let mut new_sums: Vec<i64>;

    for row in (0..(data.len() - 1)).rev() {
        new_sums = vec![]; /* reset vector to collect new sums */
        for item in 0..data[row].len() {
            if last_sums[item] > last_sums[item + 1] {
                new_sums.push(data[row][item] + last_sums[item]);
            } else {
                new_sums.push(data[row][item] + last_sums[item + 1]);
            }
        }
        last_sums = new_sums.clone();
    }

    // finally, only the largest some is left
    last_sums[0]
}
