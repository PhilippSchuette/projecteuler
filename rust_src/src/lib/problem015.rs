/* Project Euler Problem 15 Solution
 *
 * Problem statement:
 * Starting in the top left corner of a 2×2 grid, and
 * only being able to move to the right and down, there
 * are exactly 6 routes to the bottom right corner:
 *
 * --|   -|    -|    |     |     |
 *   |    -|    |_   --|   -|_   |__
 *
 * How many such routes are there through a 20×20 grid?
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/04
 * License: MIT (see ../LICENSE.md)
 */
// Returns the number of unique routes through a grid
// with n * m dimensions.
pub fn find_routes(n: i64, m: i64) -> i64 {
    // create a 2-D array to save intermediate results
    // and initialize it with 0
    let mut matrix: Vec<Vec<i64>> = vec![];

    for _ in 0..(n + 1) {
        let mut v = vec![];
        for _ in 0..(m + 1) {
            v.push(0);
        }
        matrix.push(v);
    }

    // reconstruct paths using dynamic programming
    // first, fill in all nodes in the top/bottom/
    // left/right margins since one can only go
    // forward (i.e. right/down) on the grid
    for row in 0..(n + 1) {
        matrix[row as usize][0] = 1;
        matrix[row as usize][m as usize] = 1;
    }
    for col in 0..(m + 1) {
        matrix[0][col as usize] = 1;
        matrix[n as usize][col as usize] = 1;
    }

    // next, traverse the matrix/grid backwards and
    // fill in all other nodes by adding up the node
    // to the right and to the bottom, excluding the
    // margins
    for row in (0..n).rev() {
        for col in (0..m).rev() {
            let bottom = matrix[(row + 1) as usize][col as usize];
            let right = matrix[row as usize][(col + 1) as usize];

            matrix[row as usize][col as usize] = bottom + right;
        }
    }

    // return the top-left node since it represents the sum of
    // all possible paths through the grid
    return matrix[0][0];
}
