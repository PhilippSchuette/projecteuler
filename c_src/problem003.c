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
#include <math.h> /* compile with -lm flag */

/* test for primality of input */
int is_prime(long);
/* return largest prime factor of input */
long max_prime_factor(long);
/* different implementation for largest prime factor */
long max_prime_factor2(long);


int main()
{
	long to_factor1 = 600851475143;
	long to_factor2 = 13195;
	long sol1;
	long sol2;

/*	sol1 = max_prime_factor(to_factor2); */
	sol2 = max_prime_factor2(to_factor1);

/*	printf("largest prime factor of %ld: %ld\n", to_factor2, sol1); */
	printf("largest prime factor of %ld: %ld\n", to_factor1, sol2);

	return 0;
}


int is_prime(long n)
{
	if (n == 1) { return 1; }
	else if (n == 2) { return 0; }
	else if ((n % 2) == 0) { return 1; }

	long i, j;
	double root = round(sqrt(n));
	i = ((long) root) + 1;

	j = 3;
	while (j < i) {
		if ((n % j) == 0) { return 1; }
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
	return -1; /* indicates failure of search for prime factor */
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
	return -1; /* indicates failure of search for prime factor */
}


