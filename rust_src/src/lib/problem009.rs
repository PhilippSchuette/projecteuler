/* Project Euler Problem 9 Solution
 *
 * Problem statement:
 * A Pythagorean triplet is a set of three natural numbers,
 * a < b < c, for which, a^2 + b^2 = c^2. For example,
 * 3^2 + 4^2 = 9 + 16 = 25 = 5^2. There exists exactly one
 * Pythagorean triplet for which a + b + c = 1000. Find the
 * product abc.
 *
 * Solution description:
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2018/02/28
 * License: MIT (see ../LICENSE.md)
 */
#[derive(Debug)]
pub struct Triplet {
    a: i64,
    b: i64,
    c: i64,
}

// Test whether a given triplet is Pythagorean.
fn is_triplet(t: &Triplet) -> bool {
    if i64::pow(t.c, 2) == (i64::pow(t.a, 2) + i64::pow(t.b, 2)) {
        return true;
    }
    return false;
}

// Find a Pythagorean triplet that satisfies `a + b+ c = n' as a `Triplet'.
pub fn find_pyt_triplet(n: i64) -> Triplet {
    // initialize empty triplet
    let mut t: Triplet;

    // Loop over all possible values. This can
    // be optimized for sure!
    for i in 1..(n / 2) {
        for j in 1..(n / 2) {
            t = Triplet {
                a: i,
                b: j,
                c: ((i64::pow(i, 2) + i64::pow(j, 2)) as f64).sqrt() as i64,
            };
            if is_triplet(&t) && (t.a + t.b + t.c) == n {
                return t;
            }
        }
    }

    // if no triplet is found, return all zeros
    return Triplet { a: 0, b: 0, c: 0 };
}

// Return the product of all three Triplet members.
pub fn mult_triplet(t: Triplet) -> i64 {
    return t.a * t.b * t.c;
}
