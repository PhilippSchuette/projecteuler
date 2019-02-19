/* Project Euler Problem 1 Solution */

/* Problem statement:
If we list all the natural numbers below 10 that are multiples
of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000. */

/* Solution description:
This script uses a similar formula-based algorithm as the python
implemented solution 'problem001.py'. */

/* Author: Philipp Schuette */
/* Date: 2019/02/19 */
/* License: MIT (see ../LICENSE.md) */

#include <stdio.h>

#define BOUND 1000
#define INT1 3
#define INT2 5


int summation(int x, int target) {
    /* calculates the sum of all multiples of x between
    0 and target */
    int n = (target - 1)/x;
    return x*n*(n + 1)/2;
}


int main() {
    int sum;
    sum = summation(INT1, BOUND) + summation(INT2, BOUND)
          - summation(INT1*INT2, BOUND);

    printf("Solution: %d\n", sum);
}
