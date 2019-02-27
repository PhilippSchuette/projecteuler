# Project Euler Problem 5 Solution
#
# Problem statement:
# 2520 is the smallest number that can be divided by each of
# the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible
# by all of the numbers from 1 to 20?
#
# Solution description:
# This script is a brute-force solution of the above problem,
# followed by a faster solution exploiting prime number factorization.
#
# Author: Daniel Schuette, Philipp Schuette
# Date: 2019/02/09
# License: MIT (see ../LICENSE.md)
import time

import numpy as np


def evenly_divisible(limit):
    """
    Doc string
    """
    current_num = limit  # represents the currently tested number
    divisible = True  # whether `current_num' is still divisible

    while True:
        for divisor in range(1, limit+1):
            if not (current_num % divisor) == 0:
                divisible = False
                break  # break out of for loop

        if not divisible:
            current_num += limit
            divisible = True
        else:
            return current_num


def check_prime(x):
    """
    checks, whether or not x is a prime number
    """
    prime = True
    for i in range(2, x):
        if (x % i) == 0:
            prime = False
            break
    return prime


def prime_list(n):
    """
    outputs a list of all prime numbers between 1 and n > 1
    """
    prime_list = []
    for i in range(2, n + 1):
        if check_prime(i):
            prime_list.append(i)
    return prime_list


def lcm(n):
    """
    outputs the least common multiple for the numbers from 1 to 20
    """
    primes = prime_list(n)
    lcm = 1
    for p in primes:
        e_p = 1
        while pow(p, e_p + 1) <= n:
            e_p += 1
        lcm *= pow(p, e_p)
    return lcm


if __name__ == "__main__":
    # calculate the solution with the 'slow' variant
    start1 = time.time()
    solution1 = evenly_divisible(20)
    end1 = time.time()
    # calculate the solution with the 'fast' variant
    start2 = time.time()
    solution2 = lcm(30)
    end2 = time.time()

    # print both solutions
    print("slow solution expired: {}s, solution: {}".format(
        np.round(end1 - start1, 5), solution1))
    print("fast solution expired: {}s, solution {}". format(
        np.round(end2 - start2, 5), solution2))
