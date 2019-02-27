/*
 * Compile this file to run the solutions. Helper
 * functions that solve the problems are modularized
 * and imported.
 */
mod problem001;
mod problem002;
mod problem003;
mod problem004;

fn main() {
    // run problem 1 solution
    let result = problem001::sum_multiples(1000);
    println!("Problem 1:\n\tresult: {}", result);

    // run problem 2 solution
    let fib_vec = problem002::fibonacci_vec(4000000);
    let result = problem002::sum_even_terms_vec(fib_vec);
    println!("Problem 2:\n\tresult: {}", result);

    // run problem 3 solution
    let result = problem003::largest_prime_factor(600851475143);
    // let result = problem003::largest_prime_factor(13195);
    println!("Problem 3:\n\tresult: {}", result);

    // run problem 4 solution
    let result = problem004::largest_palindrome();
    println!("Problem 4:\n\tresult: {}", result);
}
