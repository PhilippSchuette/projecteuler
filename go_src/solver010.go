package geulerproject

import (
	"fmt"
)

// SumOfPrimes takes an integer n as its input and returns the sum of all prime numbers
// smaller than n; see problem10.go for a more detailed description of the problem
func SumOfPrimes(n int) (int, error) {
	// test validity of input
	if n < 2 {
		return 0, fmt.Errorf("invalid input: %d is less than 2", n)
	}

	// find and sum the first n primes and return the result
	var sum, counter int
	currentNum := 2
	for {
		if IsPrime(currentNum) {
			counter++
			sum += currentNum
			fmt.Printf("counter: %d, current prime: %d\n", counter, currentNum)
		}
		currentNum++
		if currentNum > n {
			return sum, nil
		}
	}
}

// IsPrime returns true if the input is a prime number
func IsPrime(n int) bool {
	for i := 2; i < n; i++ {
		if (n % i) == 0 {
			return false
		}
	}
	return true
}
