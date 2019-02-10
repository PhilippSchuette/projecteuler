package geulerproject

import "fmt"

// EvenlyDivisible returns the integer that is evenly divisible by all integers from 0 up to the input; see unit tests in solver5_test.go for examples
func EvenlyDivisible(n int) (int, error) {
	// test validity of input
	if n < 1 {
		return 0, fmt.Errorf("invalid input: %d is less than 1", n)
	}

	// iterate of all integers from 0 onwards until one integer is found that is evenly divisible by all integers 0, ..., n
	var i int
	for {
		i++
		for j := 1; j <= n; j++ {
			if (i % j) != 0 {
				break
			} else if j == n {
				return i, nil
			}
		}
	}
}
