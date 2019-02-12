# template.py demonstrates how to structure the problem
# Project Euler Problem X Solution
#
# Problem statement:
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.
#
# Solution description:
# --
#
# Author: <autor_name>
# Date: 2018/../..
# License: MIT (see ../LICENSE.md)
import time

from problem003 import is_prime


def sum_primes(n):
    """
    Sum up all prime numbers below n.
    """
    sum = 0
    for i in range(n):
        # edge cases are handled by `is_prime'
        if is_prime(i):
            sum += i

    return sum


if __name__ == "__main__":
    # calculate result
    start = time.time()
    solution = sum_primes(2000000)
    end = time.time()

    # print result
    print(f"Solution: {solution}")
    print(f"Elapsed time: {(end - start):.5f}s")
