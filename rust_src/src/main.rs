/* #no_code
 * Compile this file to run the solutions. Helper functions that
 * solve the problems are modularized and imported. To run individual
 * solutions, supply a comma-separated list of problem numbers like so:
 * `$cargo run -- 1,2,5'
 * for problems 1, 2 and 5 or
 * `$./path/to/bin 1,2,5'
 * if you don't want to use cargo. A syntax for argument expansion is
 * available, too:
 * `$cargo run -- 1:7' run problems 1 through 7.
 *
 * For authorship and licensing information, see any of the problem files
 * in `lib/'.
 */
mod lib;
mod tests;
mod utils;

use lib::problem001;
use lib::problem002;
use lib::problem003;
use lib::problem004;
use lib::problem005;
use lib::problem006;
use lib::problem007;
use lib::problem008;
use lib::problem009;
use lib::problem010;
use lib::problem011;
use lib::problem012;
use lib::problem013;
use lib::problem014;
use lib::problem015;
use lib::problem016;
use lib::problem017;
use lib::problem018;

use std::env;
use std::time::Instant;

fn main() {
    // collect first command line argument or set default "none"
    let argv: Vec<String> = env::args().collect();
    let arg = if argv.len() > 1 { &argv[1] } else { "none" };

    // run solutions according to cli options
    let options: Vec<&str> = arg.split(",").collect();
    for option in options {
        // Create a vector for expanded options.
        // It needs to be a String to be heap-allocated.
        let mut opts_expanded: Vec<String> = Vec::new();
        let mut s: String;

        if option.contains(":") {
            let o_vec: Vec<&str> = option.split(":").collect();

            // For now, ignore things like `1:2:3' and silently
            // reduce to `1:2'. If parsing error are returned,
            // assume a range 0..2 by setting start=0, end=1.
            if o_vec.len() > 1 {
                let start = o_vec[0].parse::<i32>().unwrap_or(0);
                let end = o_vec[1].parse::<i32>().unwrap_or(1);

                for i in start..end + 1 {
                    s = i.to_string();
                    opts_expanded.push(s);
                }
            }
        } else {
            opts_expanded.push(option.to_string());
        }

        // iterate over options
        for opt in opts_expanded {
            println!("Running option {} -", opt);
            match opt.as_str() {
                "1" => {
                    // run problem 1 solution
                    let now = Instant::now();
                    let result = problem001::sum_multiples(1000);
                    println!(
                        "Problem 1:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed() // in microsecs
                    );
                }
                "2" => {
                    // run problem 2 solution
                    let now = Instant::now();
                    let fib_vec = problem002::fibonacci_vec(4000000);
                    let result = problem002::sum_even_terms_vec(fib_vec);
                    println!(
                        "Problem 2:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "3" => {
                    // run problem 3 solution
                    let now = Instant::now();
                    let result = problem003::largest_prime_factor(600851475143);
                    println!(
                        "Problem 3:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "4" => {
                    // run problem 4 solution
                    let now = Instant::now();
                    let result = problem004::largest_palindrome();
                    println!(
                        "Problem 4:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "5" => {
                    // run problem 5 solution
                    let now = Instant::now();
                    let result = problem005::evenly_divisible(20);
                    println!(
                        "Problem 5:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "6" => {
                    // run problem 6 solution
                    let now = Instant::now();
                    let result = problem006::solve(100, 100);
                    println!(
                        "Problem 6:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "7" => {
                    // run problem 7 solution
                    let now = Instant::now();
                    let result = problem007::nth_prime(10001);
                    println!(
                        "Problem 7:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "8" => {
                    // run problem 8 solution
                    let now = Instant::now();
                    let data = problem008::parse_data("inputs/problem008.in".to_string());
                    /* path from base dir */
                    let result = problem008::adjacent_digits(data);
                    println!(
                        "Problem 8:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "9" => {
                    // run problem 9 solution
                    let now = Instant::now();
                    let triplet: problem009::Triplet = problem009::find_pyt_triplet(1000);
                    let result = problem009::mult_triplet(triplet);
                    println!(
                        "Problem 9:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed() // in microsecs
                    );
                }
                "10" => {
                    // run problem 10 solution
                    let now = Instant::now();
                    let result = problem010::sum_primes(2_000_000);
                    println!(
                        "Problem 10:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "11" => {
                    // run problem 11 solution
                    let now = Instant::now();
                    let matrix = problem011::parse_matrix("inputs/problem011.in");
                    let result = problem011::greatest_product(matrix);
                    println!(
                        "Problem 11:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "12" => {
                    // run problem 12 solution
                    let now = Instant::now();
                    let result = problem012::solve(500);
                    println!(
                        "Problem 12:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }

                "13" => {
                    // run problem 13 solution
                    let now = Instant::now();
                    let result = problem013::sum_big_ints("inputs/problem013.in");
                    let (split, _) = result.split_at(10); /* display first 10 digits */
                    println!(
                        "Problem 13:\n\tresult: {}\n\telapsed: {:?}",
                        split,
                        now.elapsed()
                    );
                }
                "14" => {
                    // run problem 14 solution
                    let now = Instant::now();
                    let result = problem014::find_longest_collatz(1_000_000);
                    println!(
                        "Problem 14:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "15" => {
                    // run problem 15 solution
                    let now = Instant::now();
                    let result = problem015::find_routes(20, 20);
                    println!(
                        "Problem 15:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "16" => {
                    // run problem 16 solution
                    let now = Instant::now();
                    let result = problem016::sum_of_digits(2.0, 1000.0);
                    println!(
                        "Problem 16:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "17" => {
                    // run problem 17 solution
                    let now = Instant::now();
                    let result = problem017::placeholder();
                    println!(
                        "Problem 17:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }
                "18" => {
                    // run problem 18 solution
                    let now = Instant::now();
                    let result = problem018::placeholder();
                    println!(
                        "Problem 18:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                }

                // other values should just silently return from main
                "0" => return,
                "none" => return,
                _ => return,
            }
        }
    }
}
