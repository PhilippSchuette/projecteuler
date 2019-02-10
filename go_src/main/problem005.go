// Problem 5:
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
//
// problem 5 solver is implemented in solver5.go with a unit test in solver_test5.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.EvenlyDivisible(20)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
