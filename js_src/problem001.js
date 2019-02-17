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
 * Brute-force.
 *
 * Author: Daniel Schuette
 * Date: 2019/02/17
 * License: MIT (see ../LICENSE.md)
 */
"use strict";
const { performance } = require("perf_hooks");
const solver = require("./solver001.js");

// calculate solution and record the elapsed time
const start = performance.now();
const multArray = solver.listMultiples(1000, 3, 5);
const result = solver.sumOverArray(multArray);
const end = performance.now();

// log results
console.log(`elapsed: ${solver.timeIt(start, end)}`);
console.log(`result: ${result}`);
