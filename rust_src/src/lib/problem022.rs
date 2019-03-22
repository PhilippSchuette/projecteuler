/* Project Euler Problem 22 Solution
 *
 * Problem statement:
 * Using problem022.in, a 46K text file containing over five-thousand first
 * names, begin by sorting it into alphabetical order. Then working out
 * the alphabetical value for each name, multiply this value by its
 * alphabetical position in the list to obtain a name score. For example,
 * when the list is sorted into alphabetical order, COLIN, which is worth
 * 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would
 * obtain a score of 938 × 53 = 49714. What is the total of all the name
 * scores in the file?
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/22
 * License: MIT (see ../LICENSE.md)
 */
use std::fs::File;
use std::io::Read;

// Solve the problem as stated above.
pub fn solve(path: &str) -> i64 {
    // open file and read content into string
    let mut f = File::open(path).expect("Failed to open file");
    let mut data: String = String::from("");
    f.read_to_string(&mut data).expect("Failed to read file");

    // remove quotes and append data to vec
    let mut names: Vec<String> = vec![];
    for name in data.split(",") {
        let new: String = name /* last name has additional new line char */
            .trim_matches('\n')
            .trim_matches('"')
            .to_string();
        names.push(new);
    }

    // sort vector and calculate name score
    let mut score = 0;
    bubble_sort_string(&mut names);
    for i in 0..names.len() {
        score += name_score(&names[i]) * ((i+1) as i64);
    }

    score
}

// Improving this sorting algorithm would speed up the solution a lot.
pub fn bubble_sort_string(vec: &mut Vec<String>) {
    for i in 0..(vec.len()-1) {
        for j in 0..(vec.len()-1-i) {
            if vec[j] > vec[j+1] {
                // swap elements
                let tmp = vec[j].clone();
                vec[j] = vec[j+1].clone();
                vec[j+1] = tmp;
            }
        }
    }
}

// Calculate the score of a string which is the sum of its letters (A=1, B=2,
// and so on).
pub fn name_score(name: &String) -> i64 {
    let mut sum: i64 = 0;
    for b in name.bytes() {
        sum += (b-64) as i64;
    }
    sum
}
