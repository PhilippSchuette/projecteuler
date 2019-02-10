// Problem 6:
// The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)^2 = 552 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
//
// problem 6 solver is implemented in solver6.go with a unit test in solver_test6.go
package main

import (
	"fmt"
	"log"
	"time"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	start := time.Now()
	res1, err := geulerproject.SumOfSquares(1000000000)
	if err != nil {
		log.Fatal(err)
	}
	res2, err := geulerproject.SquareOfSums(1000000000)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("res1:", res1, "res2:", res2)
	fmt.Println("result:", res2-res1)
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Printf("time elapsed (slow solution): %5v\n", elapsed)

	// run fast solutions and calculate differences in execution time
	start = time.Now()
	res3, err := geulerproject.FastSumOfSquares(1000000000)
	if err != nil {
		log.Fatal(err)
	}
	res4, err := geulerproject.FastSquareOfSums(1000000000)
	if err != nil {
		log.Fatal(err)
	}
	t = time.Now()
	elapsed = t.Sub(start)
	fmt.Printf("time elapsed (fast solution): %5v\n", elapsed)

	// confirm that both solutions give the same result
	fmt.Printf("slow solution == fast solution: %v\n", (int64(res4)-int64(res3)) == (int64(res2)-int64(res1)))
}
