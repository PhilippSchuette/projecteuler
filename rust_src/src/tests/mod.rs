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
    }

    #[test]
    fn test_problem004() {
        assert_eq!(lib::problem004::is_palindrome(9009), true);
        assert_eq!(lib::problem004::is_palindrome(9809), false);

        assert_eq!(lib::problem004::reverse_str(&"ab".to_string()), "ba".to_string());

        assert_eq!(lib::problem004::largest_palindrome(), 906609);
    }
}
