package geulerproject

import (
	"fmt"
	"math"
)

// SumOfSquares squares all natural numbers up to n, adds them up, and returns the result
func SumOfSquares(n int) (float64, error) {
	// test validity of input
	if n < 0 {
		return 0, fmt.Errorf("invalid input: %v is less than 1", n)
	}

	// calculate sum of squares
	var sum float64
	for i := 0; i <= n; i++ {
		sum += math.Pow(float64(i), 2)
	}
	// fmt.Println("slow solution ==> sum is:", sum)
	return sum, nil
}

// SquareOfSums calculates the sum of all natural numbers up to n, squares it, and returns it
func SquareOfSums(n int) (float64, error) {
	// test validity of input
	if n < 0 {
		return 0, fmt.Errorf("invalid input: %v is less than 1", n)
	}

	// calculate sum, square it and return it
	var sum int
	for i := 0; i <= n; i++ {
		sum += i
	}
	// fmt.Printf("slow solution ==> sum is: %v, squared: %v\n", sum, math.Pow(float64(sum), 2))
	return math.Pow(float64(sum), 2), nil
}

// Alternative Solution:
// a more sophisticated, less 'brute-forcing' solution utilizes the formula:
//			sum('natural numbers up to n') = n(n+1) / 2
// to calculate the sum of up to n natural numbers; furthermore, the formula:
//			sum('squared natural numbers up to n') = (n/6) + n^2 * (1/2 + n/3)
// gives the sum of the squared natural numbers up to n; this speeds up the calculates for
// large numbers, as can be seen from the comparison below (commented out).

// FastSumOfSquares implements the alternative solution for deriving the sum of squared natural numbers up to n
func FastSumOfSquares(n float64) (float64, error) {
	// test validity of input
	if n < 0 {
		return 0, fmt.Errorf("invalid input: %v is less than 1", n)
	}

	// calculate sum of squares
	var sum float64
	sum = (n / 6) + (math.Pow(n, 2) * (0.5 + n/3))
	// fmt.Println("fast solution ==> sum is:", int(sum))
	return sum, nil
}

// FastSquareOfSums implements the alternative solution for deriving the sum of squared natural numbers up to n
func FastSquareOfSums(n float64) (float64, error) {
	// test validity of input
	if n < 0 {
		return 0, fmt.Errorf("invalid input: %v is less than 1", n)
	}

	// calculate sum, square it, and return it
	var sum float64
	sum = (n * (n + 1)) / 2
	// fmt.Printf("fast solution ==> sum is: %v, squared: %v\n", int(sum), math.Pow(sum, 2))
	return math.Pow(sum, 2), nil
}
