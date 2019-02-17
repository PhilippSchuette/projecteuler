/*
 * Unit testing for all JavaScript solutions.
 */
const solver001 = require("./solver001");

// Test functions that solve problem 1.
test("return list of multiples of 3 and 5 < 20", () => {
         expect(solver001.listMultiples(20, 3, 5))
             .toEqual([0, 3, 5, 6, 9, 10, 12, 15, 18]);
});

test("sum numbers in an array", () => {
    expect(solver001.sumOverArray([1, 2, 3, 4]))
        .toBe(10); // strict equality works for primitives
});

test("calculate execution times", () => {
    expect(solver001.timeIt(2.1, 4.8))
        .toBe(2.7);
});
