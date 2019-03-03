/* Project Euler Problem 4 Solution
 *
 * Problem statement:
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99. Find the largest palindrome made from the
 * product of two 3-digit numbers.
 *
 * Solution description:
 * --
 *
 * Author: Daniel Schuette
 * Date: 2019/02/27
 * License: MIT (see ../LICENSE.md)
 */
pub fn is_palindrome(n: i32) -> bool {
    let s: String = n.to_string();
    let s_reverse = reverse_str(&s);

    if s == s_reverse {
        return true;
    }
    return false;
}

pub fn reverse_str(s: &str) -> String {
    // Create byte slice. Since we know the input format,
    // utf8 code points are nothing to pay attention to.
    let ss = s.to_string();
    let bytes = ss.as_bytes();

    // revert bytes
    let mut arr_rev: Vec<u8> = Vec::new();
    for byte in bytes {
        arr_rev.insert(0, *byte); /* appends to start of vector */
    }

    // create string from reverted bytes and return
    let s_rev = String::from_utf8(arr_rev).unwrap();
    return s_rev;
}

pub fn largest_palindrome() -> i32 {
    let max_num = 999;
    let mut largest = 0;

    for i in 1..max_num + 1 {
        for j in 1..max_num + 1 {
            let prod = i * j;
            if is_palindrome(prod) && (prod > largest) {
                largest = prod;
            }
        }
    }
    return largest;
}
