/*
 * Compile this file to run the solutions. Helper
 * functions that solve the problems are modularized
 * and imported. Remove `skip' before compilation
 * to select an individual solution. This `feature'
 * will be replaced with a CLI soon.
 */
use std::time::Instant;

mod problem001;
mod problem002;
mod problem003;
mod problem004;
mod problem005;
mod problem006;
mod problem007;

fn main() {
    let skip = true;

    // run problem 1 solution
    if !skip {
        let now = Instant::now();
        let result = problem001::sum_multiples(1000);
        println!(
            "Problem 1:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed() // in microsecs
        );
    }

    // run problem 2 solution
    if !skip {
        let now = Instant::now();
        let fib_vec = problem002::fibonacci_vec(4000000);
        let result = problem002::sum_even_terms_vec(fib_vec);
        println!(
            "Problem 2:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }

    // run problem 3 solution
    if !skip {
        let now = Instant::now();
        let result = problem003::largest_prime_factor(600851475143);
        println!(
            "Problem 3:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }

    // run problem 4 solution
    if !skip {
        let now = Instant::now();
        let result = problem004::largest_palindrome();
        println!(
            "Problem 4:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }

    // run problem 5 solution
    if !skip {
        let now = Instant::now();
        let result = problem005::evenly_divisible(20);
        println!(
            "Problem 5:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }

    // run problem 6 solution
    if !skip {
        let now = Instant::now();
        let result = problem006::solve(100, 100);
        println!(
            "Problem 6:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }

    // run problem 7 solution
    if skip {
        let now = Instant::now();
        let result = problem007::nth_prime(10001);
        println!(
            "Problem 6:\n\tresult: {}\n\telapsed: {:?}",
            result,
            now.elapsed()
        );
    }
}
