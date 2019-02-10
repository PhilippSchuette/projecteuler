// Problem 10:
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// problem 10 solver is implemented in solver10.go with a unit test in solver_test10.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.SumOfPrimes(2000000)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
