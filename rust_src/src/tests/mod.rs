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
    use crate::utils;
    extern crate num_bigint;

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

    #[test]
    fn test_problem013() {
        assert_eq!(
            lib::problem013::sum_big_ints("inputs/problem013.in"),
            "5537376230390876637302048746832985971773659831892672"
        );
    }

    #[test]
    fn test_problem014() {
        assert_eq!(lib::problem014::collatz_len(1), 1);
        assert_eq!(lib::problem014::collatz_len(13), 10);

        assert_eq!(lib::problem014::find_longest_collatz(1_000_000), 837799);
    }

    #[test]
    fn test_problem015() {
        assert_eq!(lib::problem015::find_routes(2, 2), 6);
        assert_eq!(lib::problem015::find_routes(20, 20), 137846528820);
    }

    #[test]
    fn test_problem016() {
        assert_eq!(lib::problem016::sum_of_digits(2.0, 15.0), 26);
        assert_eq!(lib::problem016::sum_of_digits(2.0, 1000.0), 1366);
    }

    #[test]
    fn test_problem017() {
        // test `InputOutOfRange' error
        assert_eq!(
            lib::problem017::num_to_string(0),
            Err(utils::ParamError::InputOutOfRange)
        );

        // test string translation of various different numbers
        assert_eq!(
            lib::problem017::num_to_string(8).unwrap(),
            String::from("eight")
        );
        assert_eq!(
            lib::problem017::num_to_string(49).unwrap(),
            String::from("forty-nine")
        );
        assert_eq!(
            lib::problem017::num_to_string(107).unwrap(),
            String::from("one hundred and seven")
        );
        assert_eq!(
            lib::problem017::num_to_string(170).unwrap(),
            String::from("one hundred and seventy")
        );
        assert_eq!(
            lib::problem017::num_to_string(342).unwrap(),
            String::from("three hundred and forty-two")
        );
        assert_eq!(
            lib::problem017::num_to_string(615).unwrap(),
            String::from("six hundred and fifteen")
        );
        assert_eq!(
            lib::problem017::num_to_string(912).unwrap(),
            String::from("nine hundred and twelve")
        );
        assert_eq!(
            lib::problem017::num_to_string(900).unwrap(),
            String::from("nine hundred")
        );
        assert_eq!(
            lib::problem017::num_to_string(1000).unwrap(),
            String::from("one thousand")
        );

        assert_eq!(
            lib::problem017::str_len_exclude("three hundred and forty-two".to_string()),
            23,
        );
        assert_eq!(
            lib::problem017::str_len_exclude("one hundred and fifteen".to_string()),
            20,
        );

        assert_eq!(lib::problem017::solve(1000), 21124);
    }

    #[test]
    fn test_problem018() {
        assert_eq!(lib::problem018::find_triangle_sum("inputs/test018.in"), 23);
        assert_eq!(
            lib::problem018::find_triangle_sum("inputs/problem018.in"),
            1074
        );
    }

    #[test]
    fn test_problem019() {
        assert_eq!(lib::problem019::is_leap_year(1900), false);
        assert_eq!(lib::problem019::is_leap_year(2000), true);
        assert_eq!(lib::problem019::is_leap_year(2100), false);
        assert_eq!(lib::problem019::is_leap_year(2016), true);
        assert_eq!(lib::problem019::is_leap_year(2018), false);
        assert_eq!(lib::problem019::is_leap_year(2020), true);

        assert_eq!(lib::problem019::days_per_month(2000, 0), 31);
        assert_eq!(lib::problem019::days_per_month(2000, 8), 30);
        assert_eq!(lib::problem019::days_per_month(2000, 1), 29);
        assert_eq!(lib::problem019::days_per_month(2002, 1), 28);

        assert_eq!(lib::problem019::increment_weekday(2), 3);
        assert_eq!(lib::problem019::increment_weekday(6), 0);

        // fn doesn't have a return value, so some setup is required
        // only two cases are covered, the rest is tested via `solve()'
        let (mut d, mut m, mut y) = (28, 0, 1991);
        let expected = (29, 0, 1991);
        lib::problem019::increment_day_month_year(&mut d, &mut m, &mut y);
        assert_eq!((d, m, y), expected);

        let (mut d, mut m, mut y) = (31, 11, 1991);
        let expected = (1, 0, 1992);
        lib::problem019::increment_day_month_year(&mut d, &mut m, &mut y);
        assert_eq!((d, m, y), expected);

        // assert correct problem solution
        assert_eq!(lib::problem019::solve(), 171);
    }

    #[test]
    fn test_problem020() {
        assert_eq!(lib::problem020::solve(10), 27);
        assert_eq!(lib::problem020::solve(100), 648);
    }

    #[test]
    fn test_problem067() {
        assert_eq!(lib::problem067::find_triangle_sum("inputs/test018.in"), 23);
        assert_eq!(
            lib::problem067::find_triangle_sum("inputs/problem067.in"),
            7273
        );
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

    #[test]
    #[should_panic]
    fn test_invalid_path_013() {
        lib::problem013::sum_big_ints("invalid-path");
    } /* #no_code */

    /*
     * Tests for utility functions in `src/utils/'.
     */
    #[test]
    fn test_utils_gcd() {
        assert_eq!(utils::gcd(11, 13), 1);
        assert_eq!(utils::gcd(15, 12), 3);
        assert_eq!(utils::gcd(27, 18), 9);
        assert_eq!(utils::gcd(44, 33), 11);
    }

    #[test]
    fn test_utils_is_prime() {
        assert_eq!(utils::is_prime(1), false);
        assert_eq!(utils::is_prime(2), true);
        assert_eq!(utils::is_prime(3), true);
        assert_eq!(utils::is_prime(4), false);
        assert_eq!(utils::is_prime(10), false);
    }

    #[test]
    fn test_utils_factorial() {
        assert_eq!(
            utils::factorial(num_bigint::BigUint::from(10u32)),
            num_bigint::BigUint::from(3628800u32)
        );
    }

    #[test]
    fn test_utils_sum_of_digits() {
        assert_eq!(utils::sum_of_digits(String::from("336.0")), 12);
    }
}
