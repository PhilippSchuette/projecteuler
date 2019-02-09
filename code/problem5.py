# Project Euler Problem 5 Solution
#
# Problem statement:
# 2520 is the smallest number that can be divided by each of
# the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible
# by all of the numbers from 1 to 20?
#
# Solution description:
# This script is a brute-force solution of the above problem.
#
# Author: Daniel Schuette
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
            if not (current_num / divisor).is_integer():
                divisible = False
                break  # break out of for loop

        if not divisible:
            current_num += limit
            divisible = True
        else:
            return current_num


if __name__ == "__main__":
    # calculate the solution
    start = time.time()
    solution = evenly_divisible(20)
    end = time.time()

    # print the solution
    print("expired: {}s, solution: {}".format(
        np.round(end - start), solution))
