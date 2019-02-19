/* Project Euler Problem 1 Solution
 *
 * Problem statement:
 * If we list all the natural numbers below 10 that are multiples
 * of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Solution description:
 * This script uses a similar formula-based algorithm as the python
 * implemented solution '../py_src/problem001.py'.
 *
 * Author: Philipp Schuette, Daniel Schuette
 * Date: 2019/02/19
 * License: MIT (see ../LICENSE.md)
 */
#include <stdio.h>
#include <stdlib.h>
#include "utest.h"

#define  DEFAULT_BOUND   1000
#define  CONSTRAINT_1    3
#define  CONSTRAINT_2    5
#define  EXPECTED_RSLT   233168
#define  WRONG_RSLT      233169

long summation(long, long);

int main(int argc, char **argv)
{
    long    sum;
    long    bound;

    /* initialize unit testing */
    utest_init(&argc, argv);

    /* parse cli arguments */
    switch (argc) {
        case 1:
            bound = DEFAULT_BOUND;
            break;
        case 2:
            bound = atol(argv[1]);
            if (bound == 0) {
                fprintf(stderr, "%s: warning: %s is not valid, taking default (%d)\n",
                        argv[0], argv[1], DEFAULT_BOUND);
                bound = DEFAULT_BOUND;
            }
            break;
        default:
            fprintf(stderr, "%s: warning: too many arguments, taking default (%d)\n",
                    argv[0], DEFAULT_BOUND);
            bound = DEFAULT_BOUND;
            break;
    }

    /* calculate results */
    sum = summation(CONSTRAINT_1, bound) +
            summation(CONSTRAINT_2, bound) -
            summation(CONSTRAINT_1*CONSTRAINT_2, bound);

    /* assert equality of calculated and expected result */
    assert_equal(sum, EXPECTED_RSLT,
                 "testing equality of calulated and expected result");
    assert_not_equal(sum, WRONG_RSLT,
                     "testing unequality of calculated and wrong result");
    print_rslt_tbl();

    fprintf(stdout, "%s: solution: %ld\n", argv[0], sum);
    return 0;
}

/*
 * Calculates the sum of all multiples of x between
 * 0 and target.
 */
long summation(long x, long target)
{
    long n = (target - 1)/x;
    return (long)(x*n*(n + 1)/2);
}
