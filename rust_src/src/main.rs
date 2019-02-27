/*
 * Compile this file to run the solutions. Helper
 * functions that solve the problems are modularized
 * and imported.
 */
mod problem001;
mod problem002;
mod problem003;

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
    println!("Problem3:\n\tresult: {}", result);
}
