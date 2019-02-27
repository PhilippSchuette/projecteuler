/*
 * Compile this file to run the solutions. Helper
 * functions that solve the problems are modularized
 * and imported.
 */
mod problem001;
mod problem002;

fn main() {
    // run problem 1 solution
    let sum = problem001::sum_multiples(1000);
    println!("Problem 1:\n\tresult: {}", sum);

    // run problem 2 solution
    let fib_vec = problem002::fibonacci_vec(4000000);
    let result = problem002::sum_even_terms_vec(fib_vec);
    println!("Problem 2:\n\tresult: {}", result);
}
