# Project Euler Problem 9 Solution
#
# Problem statement:
# A Pythagorean triplet is a set of three natural numbers,
# a < b < c, for which, a^2 + b^2 = c^2. For example,
# 3^2 + 4^2 = 9 + 16 = 25 = 5^2. There exists exactly one
# Pythagorean triplet for which a + b + c = 1000. Find the
# product abc.
#
# Solution description:
# --
#
# Author: Daniel Schuette
# Date: 2018/02/12
# License: MIT (see ../LICENSE.md)
import time

import numpy as np


def pythagorean_triplet(a, b, c):
    """
    Tests whether a^2 + b^2 = c^2.
    """
    return a**2 + b**2 == c**2


def find_triplet(n):
    """
    Finds a Pythagorean triplet for which
    a + b + c = n and returns the product a*b*c.
    """
    i, j, k = 0, 0, 0
    for i in range(1, n):
        for j in range(1, n):
            k = np.sqrt(i**2 + j**2)
            if pythagorean_triplet(i, j, k) and (i+j+k) == n:
                return i*j*k


if __name__ == "__main__":
    # calculate result
    start = time.time()
    solution = find_triplet(1000)
    end = time.time()

    # print result
    print(f"Solution: {solution}")
    print(f"Elapsed time: {(end - start):.5f}s")
