/* Functions required by ./problem001.js */
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

// Takes two performance time stamps and returns the
// execution time as a difference of those two.
function timeIt(t0, t1) {
    const time = Math.round((t1 - t0)*1000)/1000;
    return time;
}

// Export functions for usage in ./problem001.js
// and ./test.js.
module.exports = { listMultiples, sumOverArray, timeIt };
