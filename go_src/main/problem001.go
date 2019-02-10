// Project Euler problem solutions written in Go.
//
// Problem 1:
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
//
// problem 1 solver is implemented in solver1.go with a unit test in solver_test1.go
// run this program to return the solution of the problem with example data
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.FindMultiples(3, 5, 0, 1000)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
