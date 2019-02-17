# Project Euler Problem 19 Solution
#
# Problem statement:
# You are given the following information, but you may prefer to do some research for yourself.

# 1 Jan 1900 was a Monday.
# Thirty days has September,
# April, June and November.
# All the rest have thirty-one,
# Saving February alone,
# Which has twenty-eight, rain or shine.
# And on leap years, twenty-nine.
# A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
# How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
#
# Solution description:
#   Bruteforce solution: Implements a simple calendar, iterates over
#   all the days and counts the number of Sundays that fell on the
#   first of a month
#   Fast solution: Iterates only over the relevant dates and 
#   uses Zeller's congruence
#   (https://en.wikipedia.org/wiki/Zeller%27s_congruence) to figure 
#   out the weekday of each first day of a month
#
# Author: Tom Praschan
# Date: 2019/02/17
# License: MIT (see ../LICENSE.md)

from math import floor
import time

def is_leapyear(year):
    """ 
    Returns True if year is a leap year and false otherwise
    """
    return year % 4 == 0 and not (year % 100 == 0 and year % 400 != 0)

def days_per_month(month, year):
    """
    Given a month (1=january, 2=february, etc.) this function
    returns the number of days in that month (leap years are) 
    taken into account
    """
    if month in [1, 3, 5, 7, 8, 10, 12]:
        return 31 
    elif month in [4, 6, 9, 11]:
        return 30 
    elif month == 2:
        return 29 if is_leapyear(year) else 28
    raise ValueError("The provided month m must fullfill 1 <= m <= 12!")

def bruteforce_solution():
    weekday = 1 # 1 = Monday, 2 = Tueday, ..., 7 = Sunday
    day = 1
    month = 1
    year = 1900

    num_sundays = 0

    while not (day == 31 and month == 12 and year == 2000):

        # Count sundays that fell on the first day of a month
        # Remember that we only start counting after 1901!
        if day == 1 and weekday == 7 and year >= 1901:
            num_sundays += 1

        # Increment date and weekday using modular arithmetic
        day = day % days_per_month(month, year) + 1
        weekday = weekday % 7 + 1

        # Increment month
        if day == 1: 
            month = month % 12 + 1

        # Increment year
        if day == 1 and month == 1:
            year += 1
    return num_sundays

def zellers_congruence(day, month, year):
    """
    For a given date year/month/day this algorithm returns 
    the weekday of that date (1 = Monday, 2 = Tuesday, etc.)
    For details see https://en.wikipedia.org/wiki/Zeller%27s_congruence
    """

    # Consistent variable names with the formula on on Wikipedia
    q = day
    if month >= 3:
        m = month 
    else:
        m = month + 12
        year -= 1
    K = year % 100
    J = year // 100
    
    h = (q + (13 * (m + 1)) // 5  + K + K // 4 + J // 4 + 5*J) % 7

    # Convert to ISO 
    return ((h + 5) % 7) + 1

def fast_solution():
    num_sundays = 0
    for year in range(1901, 2001):
        for month in range(1, 13):
            if zellers_congruence(1, month, year) == 7:
                num_sundays += 1
    return num_sundays


if __name__ == "__main__":
    start = time.time()
    solution = bruteforce_solution()
    end = time.time()

    print(f"Bruteforce Solution: {solution}")
    print(f"Elapsed time: {end - start:.6}s")

    start = time.time()
    solution = fast_solution()
    end = time.time()

    print(f"Fast Solution (Zeller's congruence): {solution}")
    print(f"Elapsed time: {end - start:.6}s")


