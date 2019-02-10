// Problem 3:
// The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143?
//
// problem 3 solver is implemented in solver3.go with a unit test in solver_test3.go
// run this program to return the solution of the problem and provide the number for which to find the largest prime factor as a command line argument to main.go
package main

import (
	"fmt"
	"log"
	"os"
	"strconv"

	"github.com/DanielSchuette/geulerproject"
)

func main() {
	if len(os.Args) != 2 {
		log.Fatal("provide the number for which to find the largest prime factor as an argument")
	}
	input, err := strconv.Atoi(os.Args[1])
	if err != nil {
		log.Fatal(err)
	}
	res, err := geulerproject.LargestPrimeFactor(input) // 600851475143
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
