/* Project Euler Problem 3 Solution
 *
 * Problem statement:
 *
 * The prime factors of 13195 are 5, 7, 13 and 29. What is
 * the largest prime factor of the number 600851475143?

 * Solution description:
 *
 * Author: PhilippSchuette
 * Date: 2019/03/10
 * License: MIT (see ../LICENSE.md)
 */

#include <stdio.h>
#include <math.h>
#include "utest/utest.h"

#define EXPECTED_RSLT1 29
#define EXPECTED_RSLT2 6857

/* test for primality of input */
int is_prime(long);

/* return largest prime factor of input */
long max_prime_factor(long);

/* different implementation for largest prime factor */
long max_prime_factor2(long);

int main(int argc, char **argv)
{
	long to_factor1 = 13195;
	long to_factor2 = 600851475143;
	long sol1;
	long sol2;

    /* initialize unit testing */
    utest_init(&argc, argv);

    /* run slow code only if any random argument was provided */
    if (argc > 1) {
        sol1 = max_prime_factor(to_factor1);
        assert_equal(sol1, EXPECTED_RSLT1,
                "testing return value of slow function");
        fprintf(stdout, "largest prime factor of %ld: %ld\n", to_factor1, sol1);
    }

    /* run fast solution */
	sol2 = max_prime_factor2(to_factor2);
    assert_equal(sol2, EXPECTED_RSLT2,
            "testing return value of fast function");
	fprintf(stdout, "largest prime factor of %ld: %ld\n", to_factor2, sol2);

    /* test edge cases for both functions */
    assert_equal(max_prime_factor(0), 0,
            "testing edge case for slow function");
    assert_equal(max_prime_factor2(0), 0,
            "testing edge case for fast function");

    /* print test results and clean up */
    print_rslt_tbl();
    utest_free_all();

	return 0;
}

/* Returns true if input is a prime number. */
int is_prime(long n)
{
	long i, j;
	double root = round(sqrt(n));

	if (n == 1) return 1;
	else if (n == 2) return 0;
	else if ((n % 2) == 0) return 1;

	i = ((long) root) + 1;
	j = 3;

	while (j < i) {
		if ((n % j) == 0)
            return 1;
		j += 2;
	}

	return 0;
}

long max_prime_factor(long n)
{
	long divisor = n;

	while (0 < divisor) {
		if ((n % divisor) == 0) {
			n = divisor;
			if (is_prime(divisor) == 0) {
				return divisor;
			}
			divisor -= 1;
		}
		divisor -= 1;
	}

    return 0;
}

long max_prime_factor2(long n)
{
	long divisor = 1;

	while (divisor < n) {
		if ((n % divisor) == 0) {
			n = n / divisor;
			if (is_prime(n) == 0) {
				return n;
			}
			divisor = 1;
		}
		divisor += 1;
	}

    return 0;
}
