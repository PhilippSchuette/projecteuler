// Problem 4:
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
//
// problem 4 solver is implemented in solver4.go with a unit test in solver_test4.go
package main

import (
	"fmt"
	"log"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	res, err := geulerproject.FindPalindrome(3)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
