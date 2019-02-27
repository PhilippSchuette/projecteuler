/*
 * Compile this file to run the solutions. Helper
 * functions that solve the problems are modularized
 * and imported. To run individual solutions, supply
 * a comma-separated list of problem numbers like so:
 * `$cargo run -- 1,2,5' for problems 1, 2 and 5 or
 * `$./path/to/bin 1,2,5' if you don't want to use
 * cargo. A syntax for argument expansion is available,
 * too: `$cargo run -- 1:7' run problems 1 through 7.
 *
 * For authorship and licensing information, see any
 * of the problem files in this directory.
 */
use std::time::Instant;
use std::env;

mod problem001;
mod problem002;
mod problem003;
mod problem004;
mod problem005;
mod problem006;
mod problem007;

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
                },
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
                },
                "3" => {
                    // run problem 3 solution
                    let now = Instant::now();
                    let result = problem003::largest_prime_factor(600851475143);
                    println!(
                        "Problem 3:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                },
                "4" => {
                    // run problem 4 solution
                    let now = Instant::now();
                    let result = problem004::largest_palindrome();
                    println!(
                        "Problem 4:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                },
                "5" => {
                // run problem 5 solution
                    let now = Instant::now();
                    let result = problem005::evenly_divisible(20);
                    println!(
                        "Problem 5:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                },
                "6" => {
                    // run problem 6 solution
                    let now = Instant::now();
                    let result = problem006::solve(100, 100);
                    println!(
                        "Problem 6:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                },
                "7" => {
                    // run problem 7 solution
                    let now = Instant::now();
                    let result = problem007::nth_prime(10001);
                    println!(
                        "Problem 7:\n\tresult: {}\n\telapsed: {:?}",
                        result,
                        now.elapsed()
                    );
                },
                "0" => return,
                "none" => return,
                _ => return,
            }
        }
    }
}
