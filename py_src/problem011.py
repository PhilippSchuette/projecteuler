# Project Euler Problem 11 Solution
#
# Problem statement:
# In the 20×20 grid below, four numbers along a diagonal line
# have been marked in red (see `input_files/problem011.txt').
# The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
# What is the greatest product of four adjacent numbers in the
# same direction (up, down, left, right, or diagonally) in the
# 20×20 grid?
#
# Solution description:
# Brute-force.
#
# Author: Daniel Schuette
# Date: 2019/02/24
# License: MIT (see ../LICENSE.md)
import time


def parse_matrix(path):
    """
    Doc string.
    """
    matrix = []

    with open(path) as f:
        for line in f:
            data = line.rstrip("\n").split(sep=" ")
            matrix.append(data)

    return matrix


def greatest_product(matrix):
    """
    Doc string.
    """
    nums = []  # temp stores data
    max_product = 0  # temp stores maximum product
    max_adjacent = 4  # number of adjacent ints to multiply

    # left/right
    for arr in matrix:
        for i in range(len(arr)-max_adjacent+1):
            prod = mult_over_list(arr[i:(i+max_adjacent)])
            if prod > max_product:
                max_product = prod

    # up/down
    for i in range(len(matrix)-max_adjacent+1):  # row
        for j in range(len(matrix[0])):  # col
            for k in range(i, (i+max_adjacent)):
                nums.append(matrix[k][j])
            prod = mult_over_list(nums)
            if prod > max_product:
                max_product = prod
            nums = []  # reset for next iteration

    # diagonal - down and left to right
    for i in range(len(matrix)-max_adjacent+1):  # row
        for j in range(len(matrix[0])-max_adjacent+1):  # col
            for idx, k in enumerate(range(i, (i+max_adjacent))):
                nums.append(matrix[k][j+idx])
            prod = mult_over_list(nums)
            if prod > max_product:
                max_product = prod
            nums = []  # reset for next iteration

    # diagonal - down and right to left
    for i in range(len(matrix)-max_adjacent+1):  # row
        for j in range(len(matrix[0])-1, -1, -1):  # col right to left!
            for idx, k in enumerate(range(i, (i+max_adjacent))):
                nums.append(matrix[k][j-idx])
            prod = mult_over_list(nums)
            if prod > max_product:
                max_product = prod
            nums = []  # reset for next iteration

    # return result
    return max_product


def mult_over_list(l):
    """
    Doc string.
    """
    product = 1
    for e in l:
        product *= int(e)
    return product


if __name__ == "__main__":
    # calculate solution and time it
    start = time.time()
    data = parse_matrix("../input_files/problem011.txt")
    solution = greatest_product(data)
    end = time.time()

    # print out results
    print(f"Solution: {solution}")
    print(f"Elapsed time: {(end - start):.6f}s")
