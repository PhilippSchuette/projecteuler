/*
 * One unit test is implemented per problem solution,
 * even when solutions have multiple functions.
 *
 * For authorship or licensing information, see files
 * in `../lib'.
 */
#[cfg(test)]
mod tests {
    use crate::lib;

    #[test]
    fn test_problem001() {
        assert_eq!(lib::problem001::sum_multiples(10), 23);
        assert_eq!(lib::problem001::sum_multiples(1000), 233168);
    }

    #[test]
    fn test_problem002() {
        assert_eq!(lib::problem002::fibonacci_vec(0), vec![]);
        assert_eq!(lib::problem002::fibonacci_vec(1), vec![1]);
        assert_eq!(lib::problem002::fibonacci_vec(2), vec![1, 2]);
        assert_eq!(lib::problem002::fibonacci_vec(10), vec![1, 2, 3, 5, 8]);

        assert_eq!(lib::problem002::sum_even_terms_vec(vec![1, 2, 3, 4]), 6);
    }

    #[test]
    fn test_problem003() {
        assert_eq!(lib::problem003::is_prime(1), false);
        assert_eq!(lib::problem003::is_prime(2), true);
        assert_eq!(lib::problem003::is_prime(3), true);
        assert_eq!(lib::problem003::is_prime(4), false);

        assert_eq!(lib::problem003::largest_prime_factor(13195), 29);
        assert_eq!(lib::problem003::largest_prime_factor(29), -1);
    }

    #[test]
    fn test_problem004() {
        assert_eq!(lib::problem004::is_palindrome(9009), true);
        assert_eq!(lib::problem004::is_palindrome(9809), false);

        assert_eq!(lib::problem004::reverse_str("ab"), "ba".to_string());

        assert_eq!(lib::problem004::largest_palindrome(), 906609);
    }

    #[test]
    fn test_problem005() {
        assert_eq!(lib::problem005::evenly_divisible(10), 2520);
    }

    #[test]
    fn test_problem006() {
        assert_eq!(lib::problem006::sum_of_squares(10), 385);

        assert_eq!(lib::problem006::square_of_sums(10), 3025);

        assert_eq!(lib::problem006::solve(10, 10), 2640);
    }

    #[test]
    fn test_problem007() {
        assert_eq!(lib::problem007::is_prime(1), false);
        assert_eq!(lib::problem007::is_prime(2), true);
        assert_eq!(lib::problem007::is_prime(3), true);
        assert_eq!(lib::problem007::is_prime(4), false);
        assert_eq!(lib::problem007::is_prime(10), false);

        assert_eq!(lib::problem007::nth_prime(6), 13);
    }

    #[test]
    fn test_problem008() {
        assert_eq!(
            lib::problem008::parse_data("inputs/test008.in".to_string()),
            "123456789123456789".to_string(),
            "parse data"
        );

        let data: String = lib::problem008::parse_data("inputs/problem008.in".to_string());
        assert_eq!(
            lib::problem008::adjacent_digits(data),
            23514624000,
            "calculate adjacent digits"
        );
    }

    #[test]
    fn test_problem009() {
        // create test data
        let t1 = lib::problem009::Triplet { a: 3, b: 4, c: 5 };
        let t2 = lib::problem009::Triplet { a: 2, b: 3, c: 4 };
        let t3 = lib::problem009::Triplet { a: 0, b: 0, c: 0 };

        // test `PartialEq' implementation
        assert_eq!(t1, t1);
        assert_ne!(t1, t2);

        // test problem009 functions
        assert_eq!(lib::problem009::is_triplet(&t1), true);
        assert_eq!(lib::problem009::is_triplet(&t2), false);

        assert_eq!(lib::problem009::find_pyt_triplet(12), t1);
        assert_eq!(lib::problem009::find_pyt_triplet(1), t3);

        assert_eq!(lib::problem009::mult_triplet(t1), 60);
    }

    #[test]
    fn test_problem010() {
        assert_eq!(lib::problem010::sum_primes(10), 17);
        assert_eq!(lib::problem010::sum_primes(2_000_000), 142913828922);
    }

    #[test]
    fn test_problem011() {
        let m = lib::problem011::parse_matrix("inputs/problem011.in");

        assert_eq!(
            lib::problem011::parse_matrix("inputs/test011.in"),
            vec![vec![1, 2], vec![3, 4], vec![5, 6]]
        );

        assert_eq!(lib::problem011::greatest_product(m), 70600674);
    }

    #[test]
    fn test_problem012() {
        assert_eq!(lib::problem012::prime_factor_powers(48), vec![4, 1]);

        assert_eq!(lib::problem012::num_divisors(1), 1);
        assert_eq!(lib::problem012::num_divisors(28), 6, "28 has 6 divisors");

        assert_eq!(lib::problem012::nth_triangle_num(7), 28);
        assert_eq!(lib::problem012::nth_triangle_num(10), 55);

        assert_eq!(lib::problem012::solve(3), 6);
        assert_eq!(lib::problem012::solve(5), 28);
    }

    // test functions that should panic, e.g. if files don't exist
    #[test]
    #[should_panic]
    fn test_invalid_path_008() {
        lib::problem008::parse_data("invalid-path".to_string());
    } /* #no_code */

    #[test]
    #[should_panic]
    fn test_invalid_path_011() {
        lib::problem011::parse_matrix("invalid-path");
    } /* #no_code */
}
