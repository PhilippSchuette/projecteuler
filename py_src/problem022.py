# Project Euler Problem 022 Solution
#
# Problem statement: Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.What is the total of all the name scores in the file?
#
# Solution description: Uses regex to extract the names from the file, sorts them using Python's built-in function and then works out each name's score
#
# Author: Tom Praschan
# 2019/02/20
# License: MIT (see ../LICENSE.md)

import re
import time

def alphabetical_value(name):
    """
    Returns the alphabetical value of a name as described in the
    problem statement. 
    """
    return sum([ord(c) - 64 for c in list(str(name))])


if __name__ == "__main__":
    start = time.time()

    # Extract names from the input file 
    names = [m for m in re.findall('(?<=")[A-Z]+(?=")', open('../input_files/names.txt').read())]

    # Sort alphabetically
    names.sort()

    # Multiply each name's alphabetical value by it's position 
    # in the list and sum those up
    solution = sum((i+1) * alphabetical_value(name) for i, name in enumerate(names))

    end = time.time()

    print(f"Solution: {solution}")
    print(f"Elapsed time: {end-start:.6}s")
