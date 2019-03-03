# Project Euler Problem 025 Solution
#
# The Fibonacci sequence is defined by the recurrence relation:
#
# Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
# Hence the first 12 terms will be:
#
# F1 = 1
# F2 = 1
# F3 = 2
# F4 = 3
# F5 = 5
# F6 = 8
# F7 = 13
# F8 = 21
# F9 = 34
# F10 = 55
# F11 = 89
# F12 = 144
# The 12th term, F12, is the first term to contain three digits.
# What is the index of the first term in the Fibonacci sequence to
# contain 1000 digits?
#
# Solution description:
# Obvious brute force approach: Compute Fibonacci numbers until number
# of digits is exceeded.
#
# Author: Tom Praschan
# 2019/02/01
# License: MIT (see ../LICENSE.md)
import time


def num_digits(n):
    """
    Given a number n, this function returns its number of digits in base 10.
    """
    return len(str(n))


if __name__ == "__main__":
    start = time.time()

    f1 = 1
    f2 = 1
    index = 2
    while(num_digits(f2) != 1000):
        temp = f2
        f2 += f1
        f1 = temp
        index += 1

    end = time.time()

    print(f"Solution: {index}")
    print(f"Elapsed time: {end-start:.6}s")
