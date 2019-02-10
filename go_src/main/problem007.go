// Problem 7:
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?
//
// problem 7 solver is implemented in solver7.go with a unit test in solver_test7.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.FindPrimeNumber(10001)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
