# Project Euler Problem 5 Solution
#
# Problem statement:
# By listing the first six prime numbers: 2, 3, 5, 7, 11,
# and 13, we can see that the 6th prime is 13. What is the
# 10 001st prime number?
#
# Solution description:
# This script uses a brute-force approach to determine the
# n'th prime number. Currently, the solution takes about
# 60s to determine the 10,001 prime number.
#
# Author: Daniel Schuette
# Date: 2018/02/10
# License: MIT (see ../LICENSE.md)
import time

import numpy as np
from problem3 import is_prime


def nth_prime(n):
    """
    Determine the n'th prime number using a brute-force
    approach.
    """
    if n == 1:
        return 2

    current_num = 3
    num_primes = 1  # 2 is already included

    while True:
        if is_prime(current_num):
            num_primes += 1
            if num_primes == n:
                return current_num

        current_num += 2  # even numbers aren't prime!


if __name__ == "__main__":
    # calculate result and time it
    start = time.time()
    target = 10001
    solution = nth_prime(target)
    end = time.time()

    # print result
    print("expired: {}s, solution: {}".format(
        np.round(end - start), solution))
