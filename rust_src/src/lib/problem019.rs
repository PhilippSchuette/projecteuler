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
const WEEKDAYS: [&str; 7] = [
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
];

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
    let days = MONTHS[month];
    if days == 28 && is_leap_year(year) {
        return 29;
    }
    days
}

// Increment weekdays in range [0, 7). No error checking is performed.
pub fn increment_weekday(day: usize) -> usize {
    if day == 6 {
        return 0;
    }
    day + 1
}

// Increment day, month, and year. No error checking is performed.
pub fn increment_day_month_year(day: &mut i64, month: &mut usize, year: &mut i64) {
    let days_this_month = days_per_month(*year, *month);
    *day += 1;

    // increment month and possibly year if next month is reached
    if *day > days_this_month {
        *day = 1; /* reset day to first of month */
        if *month < 11 {
            *month += 1; /* increment month by 1 */
        } else if *month == 11 {
            *month = 0; /* reset month to January */
            *year += 1; /* increment year by 1 */
        }
    }
}

// Solve the problem as stated above.
pub fn solve() -> i64 {
    let mut sunday_count = 0; /* number of Sundays on 1st of month */
    let mut current_month = 0; /* current month as an int, [0, 11] */
    let mut current_day = 1; /* day of the current month, [1, 31] */
    let mut current_weekday = 0; /* current day, indexes into WEEKDAYS */
    let mut current_year = 1900; /* current year */

    while current_year >= 1900 && current_year <= 2000 {
        // check condition and increment the counter
        if current_year > 1900 && WEEKDAYS[current_weekday] == "Sunday" && current_day == 1 {
            sunday_count += 1;
        }

        // increment all looping variables
        increment_day_month_year(&mut current_day, &mut current_month, &mut current_year);
        current_weekday = increment_weekday(current_weekday);
    }

    sunday_count
}
