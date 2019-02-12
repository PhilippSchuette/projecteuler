# Project Euler Problem 8 Solution
#
# Problem statement:
# Work out the first ten digits of the sum of the following one-
# hundred 50-digit numbers (see ../input_files/problem013.txt).
#
# Solution description:
# Since Python ints use arbitrary precision we can just sum up all
# the numbers without worrying about integer overflow. When arbitrary
# precision is no available, one would probably have to use long
# division.
#
# Author: Tom Praschan
# Date: 2019/02/11
# License: MIT (see ../LICENSE.md)
import time


def sum_numbers(nums):
    """
    Given a list of numbers, this function calculates the sum
    Since python ints use arbitrary precision, we don't have
    to worry about overflow errors
    """
    nums = list(map(int, nums))  # Convert to a list of ints
    return sum(nums)  # Just sum up all the numbers - Magic!


if __name__ == "__main__":
    # Convert the input to a list of strings
    nums = [l.strip('\n') for l in open("../input_files/problem013.txt").readlines()]

    start = time.time()
    solution = str(sum_numbers(nums))[:10]
    end = time.time()
    print(f"Solution: {solution}")
    print(f"Elapsed time: {(end - start):.6f}s")
