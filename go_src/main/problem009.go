// Problem 9:
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product a*b*c.
//
// problem 9 solver is implemented in solver9.go with a unit test in solver_test9.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	a, b, c, err := geulerproject.PythagoreanTriplet(1000)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("a: %v, b: %v, c: %v, sum: %v, product: %v\n", a, b, c, a+b+c, a*b*c)
}
