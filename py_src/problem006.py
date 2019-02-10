# Project Euler Problem 6 Solution
#
# Problem statement:
# The sum of the squares of the first ten natural numbers is,
# 1^2 + 2^2 + ... + 10^2 = 385. The square of the sum of the
# first ten natural numbers is (1 + 2 + ... + 10)^2 = 55^2 = 3025.
# Hence the difference between the sum of the squares of the
# first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
# Find the difference between the sum of the squares of the first
# one hundred natural numbers and the square of the sum.
#
# Solution description:
# Simple algebraic manipulations show, that the required sum equals
# 2*1*(2 + 3 + ... + n) + 2*2*(3 + 4 + 5 + ... + n) + 2*3*...
# This approach is implemented directly as a function with n as input.
# For some further utility, the function also takes another input m with
# default value m = 1, which determines the starting point for the summation.
#
# Author: Philipp Schuette
# Date: 2019/02/10
# License: MIT (see ../LICENSE.md)

import time
import numpy as np


def calc_sums(m, n):
	sum1 = 0  # gets incremented towards the final value
	sum2 = int((n*(n + 1) - m*(m + 1))/2)  # stores intermediate sums
	for i in range(m, n):
		sum1 += i*sum2
		sum2 -= (i + 1)
	return 2*sum1


if __name__ == "__main__":
    # calculate result and time it
    start = time.time()
    target = 100
    solution = calc_sums(1, target)
    end = time.time()

    # print result
    print("expired: {}s, solution: {}".format(
    np.round(end - start, 5), solution))
