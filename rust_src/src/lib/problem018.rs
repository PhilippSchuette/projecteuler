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
// Returns the largest sum of numbers in the triangle located
// at `path'. See the problem statement above for additional
// information.
pub fn find_triangle_sum(path: &str) -> i64 {
    println!("{}", path);
    return 0;
}
