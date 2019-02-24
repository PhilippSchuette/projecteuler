/* Functions required by ./problem002.js */
"use strict";
const { performance } = require("perf_hooks");

// Returns an array of Fibonacci numbers smaller
// than `n'.
function fibonacciArr(n) {
    const arr = [ 1, 2 ];
    let current = 1, temp = 0, next = 2;

    while (true) {
        temp = next;
        next += current;
        current = temp;
        if (next >= n) break;
        arr.push(next);
    }
    return arr;
}

// Sums up the even elements of an input array.
function sumOverArrayEven(arr) {
    let sum = 0;

    arr.forEach((elem) => {
        if (elem % 2 === 0)
            sum += elem;
    });
    return sum;
}

// Export functions for usage in ./problem002.js
// and ./test.js.
module.exports = { fibonacciArr, sumOverArrayEven };
