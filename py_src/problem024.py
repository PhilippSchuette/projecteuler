# Project Euler Problem 24 Solution
#
# Problem statement:
# A permutation is an ordered arrangement of objects.  For example, 3124
# is one possible permutation of the digits 1, 2, 3 and 4.  If all of
# the permutations are listed numerically or alphabetically, we call it
# lexicographic order.  The lexicographic permutations of 0, 1 and 2
# are:  012   021   102   120   201   210
# What is the millionth lexicographic permutation of the digits 0, 1, 2,
# 3, 4, 5, 6, 7, 8 and 9?
#
# Solution description:
# Brute force, see wikipedia entry 'permutation', paragraph 'algorithms
# to generate permutations'.  The algorithm generates the
# lexicographically next permutation from a given permutation a0...an in
# the following steps:
# 1. Find the largest k, such that a[k] < a[k+1]
# 2. Find the largest l, such that a[k] < a[l]
# 3. Swap a[k] and a[l]
# 4. Reverse the suffix a[k+1]...a[n]
#
# In short, step 1 finds the largest prefix, which is sorted in
# descending order.  Step 2 finds the smallest value larger than a[k] in
# this suffix.  After the swap in step 3, step 4 reverses the resulting
# suffix, which brings it into ascending order.
#
# Author: Philipp Schuette
# Date: 2019/06/12
# License: MIT (see ../LICENSE.md)


def next_perm(permu):
    """
    Function, which takes a given permutation as input and returns the
    lexicographically next permutation.
    Checks are implemented for correct input of a permutation and
    availability of a greater permutation.
    """
    order = len(permu)
    # Implement rudimentary checks on permu:
    for i in range(order):
        if type(permu[i]) != int:
            print("A permutation must be represented by a list of ints!")
            return(permu)
        if (permu[i] >= order or permu[i] < 0):
            print("The entries of your permutation are out of bounds!")
            return(permu)

    # The actual algorithm described above starts here:
    pivot = -1
    # Find the endpoint 'pivot', where the constant prefix ends:
    for k in range(order - 1, 0, -1):
        if permu[k] > permu[k - 1]:
            pivot = k - 1
            break
    if pivot == -1:
        print("You have already provided the largest permutation!")
        return(permu)

    # Find the next largest value, compared to permu[pivot], in the
    # suffix_
    for l in range(order - 1, pivot, -1):
        if permu[pivot] < permu[l]:
            swap = l
            break

    # Swap the values permu[pivot] and permu[swap]:
    tmp = permu[pivot]
    permu[pivot] = permu[swap]
    permu[swap] = tmp

    # Reverse the suffix permu[pivot+1:order]:
    reverse = [permu[i] for i in range(order - 1, pivot, -1)]
    for i in range(pivot + 1, order):
        permu[i] = reverse[i - (pivot + 1)]

    return(permu)

# Test next_perm with easily checkable permutation:
# init_permu = [0, 1, 2]
# print(init_permu)
# permu = init_permu
#
# for i in range(0, 5):
#     permu = next_perm(permu)
#     print(permu)


# Calculate the answer to the Project Euler question:
init_permu = [i for i in range(10)]

for i in range(1, 1000000 - 1):
    init_permu = next_perm(init_permu)

# Permutation right before the desired one, just to check:
print(init_permu)

# This is the sought after permutation:
init_permu = next_perm(init_permu)
print(init_permu)

# This is the permutation right after the solution, again for checking:
print(next_perm(init_permu))
