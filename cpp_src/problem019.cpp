/*Project Euler Problem 19 Solution

Problem statement:
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Solution description: Iterates only over the relevant dates and 
uses Zeller's congruence 
(https://en.wikipedia.org/wiki/Zeller%27s_congruence) to figure 
out the weekday of each first day of a month

Author: Tom Praschan
Date: 2019/02/17
License: MIT (see ../LICENSE.md) */

/* For a given date year/month/day this algorithm returns 
the weekday of that date (1 = Monday, 2 = Tuesday, etc.)
For details see https://en.wikipedia.org/wiki/Zeller%27s_congruence */

#include <iostream>
#include <omp.h>

unsigned zellers_congruence(unsigned day, unsigned month, unsigned year) {
    // Consistent variable names with the formula on on Wikipedia
    unsigned q = day;
    unsigned m;
    if (month >= 3)
        m = month;
    else {
        m = month + 12;
        year--;
    }
    unsigned K = year % 100;
    unsigned J = year / 100;
    
    unsigned h = (q + (13 * (m + 1)) / 5  + K + K / 4 + J / 4 + 5*J) % 7;

    // Convert to ISO 
    return ((h + 5) % 7) + 1;
}

int main() {
    auto start = omp_get_wtime();
    unsigned num_sundays = 0;
    for (unsigned year = 1901; year <= 2000; year++)
        for (unsigned month = 1; month <= 12; month++)
            if (zellers_congruence(1, month, year) == 7)
                num_sundays++;
    auto end = omp_get_wtime();

    std::cout << "Solution: " << num_sundays << "\n";
    std::cout << "Elapsed time: " << end - start << "\n";
}
