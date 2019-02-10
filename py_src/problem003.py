# Project Euler Problem 2 Solution
#
# Problem statement:
# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143 ?
#
# Solution description:
#
# Author: Daniel Schuette
# Date: 2018/09/30
# License: MIT (see ../LICENSE.md)


def is_prime(n):
    """
    This function returns a boolean value indicating whether
    the input `n' is a primer number or not.
    """
    for i in range(n):
        if (i == 0) or (i == 1):
            continue
        if (n % i) == 0:
            return False
    return True


def largest_prime_factor(n, div=2):
    """
    This function returns the largest prime factor of
    input integer `n'.
    """
    target = n
    i = n // div  # the largest prime factor must be smaller than n//div
    while True:
        i -= 1
        if i <= 1:
            break  # pragma: no cover
        if (target % i) == 0:
            if is_prime(i):
                return i


if __name__ == "__main__":
    target = 600851475143

    # `largest_prime_factor' implements the brute-force solution
    print(largest_prime_factor(target, div=2900))