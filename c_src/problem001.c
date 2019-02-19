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
 * Author: Philipp Schuette
 * Date: 2019/02/19
 * License: MIT (see ../LICENSE.md)
 */
#include <stdio.h>
#include <stdlib.h>

#define BOUND 1000
#define CONSTRAINT_1 3
#define CONSTRAINT_2 5

int summation(long, long);

int main(int argc, char **argv)
{
    int     sum;
    long    bound;

    switch (argc) {
        case 1:
            bound = BOUND;
            break;
        case 2:
            bound = atol(argv[1]);
            if (bound == 0) {
                fprintf(stderr, "%s: error: %s is not valid\n",
                        argv[0], argv[1]);
                exit(1);
            }
            break;
        default:
            fprintf(stderr, "%s: error: too many arguments\n",
                    argv[0]);
            exit(1);
    }

    sum = summation(CONSTRAINT_1, bound) +
            summation(CONSTRAINT_2, bound) -
            summation(CONSTRAINT_1*CONSTRAINT_2, bound);

    fprintf(stdout, "%s: solution: %d\n", argv[0], sum);
    return 0;
}

/*
 * Calculates the sum of all multiples of x between
 * 0 and target.
 */
int summation(long x, long target)
{
    long n = (target - 1)/x;
    return x*n*(n + 1)/2;
}
