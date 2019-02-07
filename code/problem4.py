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

def is_palindrome(n):
    """
    Checks wether n is a palindrome by converting it to a string and and comparing it to the reversed string
    """
    return str(n) == str(n)[::-1]

if __name__ == "__main__":
    largest = 0

    start = time.time()
    for i in range(100, 1000):
        for j in range(i, 1000): # Save some time here by starting at i (exploiting commutativity)
            n = i * j
            if n > largest and is_palindrome(n):
                largest = n
    
    end = time.time()

    print(f"Solution: {largest}")
    print(f"Elapsed time: {(end - start):.6f}s")

