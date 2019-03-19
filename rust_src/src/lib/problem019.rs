/* Project Euler Problem 19 Solution
 *
 * Problem statement:
 * You are given the following information, but you may prefer
 * to do some research for yourself.
 *     - 1 Jan 1900 was a Monday.
 *     - Thirty days has September, April, June and November.
 *     - All the rest have thirty-one, Saving February alone,
 *       which has twenty-eight, rain or shine. And on leap years,
 *       twenty-nine.
 *     - A leap year occurs on any year evenly divisible by 4,
 *       but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the
 * twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *
 * Solution description:
 * Brute-force.
 *
 * Authors: Daniel Schuette
 * Date: 2019/03/15
 * License: MIT (see ../LICENSE.md)
 */
const MONTHS: [i64; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

pub fn is_leap_year(year: i64) -> bool {
    if year % 100 == 0 {
        if year % 400 == 0 {
            return true;
        } else {
            return false;
        }
    }
    if year % 4 == 0 {
        return true;
    }
    false
}

// Returns the days in a particular month (January is 1,
// February is two, and so on). The year must be provided
// to determine the number of days in February.
pub fn days_per_month(year: i64, month: usize) -> i64 {
    let days = MONTHS[month-1];
    if days == 28 && is_leap_year(year) {
        return 29;
    }
    days
}
