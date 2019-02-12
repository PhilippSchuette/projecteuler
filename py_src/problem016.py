# Project Euler Problem 16 Solution
#
# Problem statement:
# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
# What is the sum of the digits of the number 2^1000?
#
# Solution description:
# --
#
# Author: Tom Praschan
# Date: 2019/02/12
# License: MIT (see ../LICENSE.md)
import time


def digit_sum(n):
    """
    Returns the sum of the digits of n in base 10
    """
    return sum([int(d) for d in str(n)])


if __name__ == "__main__":
    start = time.time()
    solution = digit_sum(2**1000)
    end = time.time()
    print(f"Solution: {solution}")
    print(f"Elapsed time: {(end - start):.6f}s")
