package geulerproject

import "fmt"

// LargestPrimeFactor takes an integer and returns the largest prime factor of that number
// see unit test in solver3_test.go for examples
func LargestPrimeFactor(num int) (int, error) {
	// check validity of input
	switch {
	case num < 1:
		return 0, fmt.Errorf("invalid input: %d is less than 1", num)
	case num == 1:
		return 1, nil
	case num == 2:
		return 2, nil
	}

	// check if input is a prime number
	prime, err := IsPrimeNumber(num)
	if err != nil {
		fmt.Printf("cannot determine if %d is a prime number: %v\n", num, err)
	}
	if prime {
		return num, nil
	}

	// solution 1: brute force with increasing prime factors that are added to an array
	/*
		// initialize an empty slice and append all prime numbers that are factors of the input integer
		primes := []int{2}
		// exclude all numbers that are divisible by 2 upfront (except for 2 itself) via incrementing with 2
		for i := 3; i < num; i += 2 {
			if (num%i) == 0 && !((i % 2) == 0) {
				p, err := IsPrimeNumber(i)
				if err != nil {
					fmt.Printf("cannot determine if %d is a prime number: %v\n", i, err)
					continue
				}
				if p {
					primes = append(primes, i)
				}
			}
		}
		return primes[(len(primes) - 1)], nil
	*/

	// solution 2: brute force with decreasing potential prime factors with the first one being returned
	/*
		for i := num; i > 2; i -= 2 {
			if (num%i) == 0 && !((i % 2) == 0) {
				p, err := IsPrimeNumber(i)
				if err != nil {
					fmt.Printf("cannot determine if %d is a prime number: %v\n", i, err)
					continue
				}
				if p {
					return i, nil
				}
			}
			if (i % 1000000000) == 0 {
				fmt.Println(i)
			}
		}
		return 0, fmt.Errorf("cannot find a prime number")
	*/

	// solution 3: iterate over possible divisors of 'num', divide 'num' by those divisors  and test if the result is a prime number
	// this solution is much more memory efficient and runs in well below 2 seconds on my machine
	for i := 2; i < num; i++ {
		if (num % i) == 0 {
			p, err := IsPrimeNumber(num / i)
			if err != nil {
				fmt.Printf("cannot determine if %d is a prime number: %v\n", (num / i), err)
				continue
			}
			if p {
				return num / i, nil
			}
		}
	}
	return 0, fmt.Errorf("cannot find a prime number")
}

// IsPrimeNumber takes an integer and returns a boolean indicating whether the input is a prime number or not or an error if the input is invalid
func IsPrimeNumber(in int) (bool, error) {
	// check validity of input
	switch {
	case in < 1:
		return false, fmt.Errorf("invalid input: %d is less than 1", in)
	case in == 1:
		return false, nil
	}

	// iterate over all integers smaller than input and return true if no modulo is 0
	for i := 2; i < in; i++ {
		if (in % i) == 0 {
			return false, nil
		}
	}
	return true, nil
}
