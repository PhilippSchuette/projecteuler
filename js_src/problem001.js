/*
 * Project Euler Problem 1 Solution
 *
 * Problem statement:
 * If we list all the natural numbers below 10 that are
 * multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of
 * these multiples is 23. Find the sum of all the multiples
 * of 3 or 5 below 1000.
 *
 * Solution description:
 *
 * Author: Daniel Schuette
 * Date: 2019/02/17
 * License: MIT (see ../LICENSE.md)
 */
"use strict";
const { performance } = require("perf_hooks");

// Returns an array of numbers below `target' that are
// multiples of `a' and `b'.
function listMultiples(target = 1000, a = 3, b = 5) {
    let multiples = [];

    for (let i = 0; i < target; i++)
        if ((i % a === 0) || (i % b === 0))
            multiples.push(i);

    return multiples;
}

// Sums up all numbers in an input array `arr'.
function sumOverArray(arr) {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    return sum;
}

// Takes two performance time stamps and logs the
// execution time as a difference of those two.
function timeIt(t0, t1) {
    const msg = `elapsed: ${Math.round((t1 - t0)*1000)/1000}`;
    console.log(msg);
}

// calculate solution and record the elapsed time
const start = performance.now();
const multArray = listMultiples();
const result = sumOverArray(multArray);
const end = performance.now();

// log results
timeIt(start, end);
console.log(`result: ${result}`);
