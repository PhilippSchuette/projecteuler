// Problem 8:
// The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
//
// problem 8 solver is implemented in solver8.go with a unit test in solver_test8.go; the 1000-digit number is hard-coded as a string variable in solver8.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.FindGreatestProduct(13)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
