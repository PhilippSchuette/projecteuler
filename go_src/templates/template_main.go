// Problem 6:
// TODO: add description
//
// problem 6 solver is implemented in solver6.go with a unit test in solver_test6.go
package main

import (
	"fmt"
	"log"
)

func main() {
	res, err := geulerproject.SOLVER()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(res)
}
