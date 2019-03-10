/* Project Euler Problem 17 Solution
 *
 * Problem statement:
 * If the numbers 1 to 5 are written out in words:
 * one, two, three, four, five, then there are
 * 3 + 3 + 5 + 4 + 4 = 19 letters used in total. If all
 * the numbers from 1 to 1000 (one thousand) inclusive
 * were written out in words, how many letters would be
 * used? Do not count spaces or hyphens. For example, 342
 * (three hundred and forty-two) contains 23 letters and
 * 115 (one hundred and fifteen) contains 20 letters. The
 * use of "and" when writing out numbers is in compliance
 * with British usage.
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/05
 * License: MIT (see ../LICENSE.md)
 */
use crate::utils;

// Get a long string representation of a number between 1 and 1000,
// e.g. `32' -> `thirty-two' and `112' -> `one hundred and twelve'.
pub fn num_to_string(num: i32) -> Result<String, utils::ParamError> {
    // FIXME: cannot deal with numbers that aren't within [1,1000]
    if num < 0 || num > 1000 {
        return Err(utils::ParamError::InputOutOfRange);
    }
    let mut input = num;

    // `ones', `ten_to_nineteen', `tens' and `hundreds' can be indexed
    // to translate numbers into a string
    let ones = [
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];
    let eleven_to_nineteen = [
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    ];
    let tens = [
        "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
    ];
    let hundreds = ["hundred"];
    let thousands = ["thousand"];

    // start with an empty string loop over the input to
    // create a string representation of it
    let mut buf = String::from("").to_owned();

    if input >= 1000 {
        let idx = (input / 1000) as usize;
        buf = format!("{} {} {}", buf, ones[idx - 1], thousands[0]);
        input -= (input / 1000) * 1000;
    }
    if input >= 100 {
        let idx = (input / 100) as usize;
        buf = format!("{} {} {}", buf, ones[idx - 1], hundreds[0]);
        input -= (input / 100) * 100;

        // if there is more to be added onto `buf',
        // add an `and' to the string
        if input > 0 {
            buf = format!("{} and", buf);
        }
    }
    if input >= 10 {
        // numbers in range [11, 19] are special and
        // must be dealt with separatley
        if input > 10 && input < 20 {
            let idx = (input % 10) as usize;
            buf = format!("{} {}", buf, eleven_to_nineteen[idx - 1]);
            input = 0;
        } else {
            let idx = (input / 10) as usize;
            buf = format!("{} {}", buf, tens[idx - 1]);
            input -= (input / 10) * 10;

            // if there is even more to come, add a `-'
            if input > 0 {
                buf = format!("{}-", buf);
            }
        }
    }
    if input >= 1 {
        let idx = input as usize;
        if buf.ends_with("-") {
            buf = format!("{}{}", buf, ones[idx - 1]);
        } else {
            buf = format!("{} {}", buf, ones[idx - 1]);
        }
    }

    // strip off leading whitespace and return
    while buf.starts_with(" ") {
        let split: Vec<&str> = buf.splitn(2, " ").collect();
        buf = split[1].to_string();
    }
    return Ok(buf);
}

// Returns the number of letters in a `word', excluding white space
// and hyphens.
pub fn str_len_exclude(word: String) -> i64 {
    let mut num_letters: i64 = 0;

    for c in word.chars() {
        if c != ' ' && c != '-' {
            num_letters += 1;
        }
    }
    return num_letters;
}

// Returns the problem solutions as state above.
pub fn solve(range: i64) -> i64 {
    let mut sum: i64 = 0;

    for i in 1..(range + 1) as i32 {
        let word = num_to_string(i).unwrap();
        sum += str_len_exclude(word);
    }
    return sum;
}
