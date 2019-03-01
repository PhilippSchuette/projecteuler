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
}
