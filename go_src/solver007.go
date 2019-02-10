package geulerproject

import "fmt"

// FindPrimeNumber takes an integer n and returns the n'th prime number
func FindPrimeNumber(n int) (int, error) {
	// check validity of input
	if n < 1 {
		return 0, fmt.Errorf("invalid input: %d is less than 1", n)
	}

	// find n'th prime number
	var counter int
	number := 1
loop:
	for {
		// increment the current number that is tested
		number++

		// all prime numbers except for 2 are odd
		if (number != 2) && ((number % 2) == 0) {
			continue loop
		}

		// test if current number is evenly divisible by an previous number (and thus, not a prime number)
		for i := 2; i < number; i++ {
			// if number is not a prime number, continue with outer loop
			if (number % i) == 0 {
				continue loop
			}
		}

		// if inner loop does not continue to outer loop, increment prime number counter
		counter++

		// if counter reached the desired n, return the current number
		if counter == n {
			return number, nil
		}
	}
}
