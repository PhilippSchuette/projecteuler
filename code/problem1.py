# template.py demonstrates how to structure the problem
# solutions:
#
# Problem statement:
# If we list all the natural numbers below 10 that are multiples
# of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#
# Solution description:
# TODO: write description
#
# Authors: Philipp Schuette, Daniel Schuette
# Date: 2018/09/24
# License: MIT (see ../LICENSE.md)
import time

import numpy as np


def slow_divisible(a=3, b=5, target=1000):
    """
    this function calculates the sum of all integers from 0 to
    `target' that are divisible by `a' or `b' with a reminder
    of 0
    -------------------------
    params:
        a, b    - the integers that are used for the modulo operation
        target  - the interval over which to calculate the sum
    """
    sum = 0
    for i in range(target):
        if (i % 3) == 0:
            sum += i
        elif (i % 5) == 0:
            sum += i
    return sum


def fast_summation(x, target):
    """

    """
    n = (target - 1) // x
    sum = x * n * (n + 1) / 2
    return sum


def fast_divisible(a=3, b=5, target=1000):
    """

    """
    sum = (fast_summation(a, target) + fast_summation(b, target) -
           fast_summation(a * b, target))
    return sum


# get a target from the user
target = int(input("please provide a positive integer: "))

# time the slow function
slow_start = time.time()
slow_solution = slow_divisible(target=target)
slow_end = time.time()
slow_time = slow_end - slow_start

# time the fast function
fast_start = time.time()
fast_solution = fast_divisible(target=target)
fast_end = time.time()
fast_time = fast_end - fast_start

# print the results
print("slow solution: {}\nfast solution: {}".format(
    slow_solution,
    fast_solution,
))
print("slow time: {}s\nfast time: {}s".format(
    np.round(slow_time, 6), np.round(fast_time, 6)))
