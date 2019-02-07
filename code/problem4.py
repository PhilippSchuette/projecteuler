#!/usr/bin/env python3

# Project Euler Problem 2 Solution
# Problem statement: 
# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product of two 3-digit numbers.

# Solution description: TODO

# Author: Tom Praschan
# Date: 2018/2/7
# License: MIT (see ../LICENSE.md)

import time
import argparse

def is_palindrome(n):
    """
    Checks wether n is a palindrome by converting it to a string and and comparing it to the reversed string
    """
    return str(n) == str(n)[::-1]

if __name__ == "__main__":

    # Parse command line arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", type=int, default=3, help="Number of digits of the two multiplicands generating the palindrome number. E.g. D=3 for the problem solution (default) or D=2 for the example in the problem statement.")
    args = parser.parse_args()

    start = time.time()

    min = 10**(args.d-1)
    max = 10**(args.d)
    largest = 0
    for i in range(min, max):
        for j in range(i, max): # Save some time here by starting at i (exploiting commutativity)
            n = i * j
            if n > largest and is_palindrome(n):
                largest = n
    
    end = time.time()

    print(f"Solution: {largest}")
    print(f"Elapsed time: {(end - start):.6f}s")

