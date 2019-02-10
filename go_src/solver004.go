package geulerproject

import (
	"fmt"
	"log"
	"strconv"
)

// FindPalindrome takes an integer argument and finds the largest palindrome made from the product of two n-digit numbers (where n is the integer argument)
func FindPalindrome(n int) (int, error) {
	// test validity of input
	switch {
	case n < 1:
		return 0, fmt.Errorf("invalid input: %d is less than 1", n)
	default:
		// continue with algorithm
	}

	// generate highest integer to start with and lowest integer at which the iteration should be stopped
	var high string
	var low string
	for i := 0; i < n; i++ {
		high = high + "9"
		if i == 0 {
			low = low + "1"
			continue
		}
		low = low + "0"
	}
	highInt, err := strconv.Atoi(high)
	if err != nil {
		log.Fatalf("cannot convert ascii to int %s: %v\n", high, err)
	}
	lowInt, err := strconv.Atoi(low)
	if err != nil {
		log.Fatalf("cannot convert ascii to int %s: %v\n", low, err)
	}

	// loop over all possible integers and test if their product is a palindrome
	var pal int
	for x := highInt; x >= lowInt; x-- {
		for y := highInt; y >= lowInt; y-- {
			ok, err := IsPalindrome(x * y)
			if err != nil {
				fmt.Printf("cannot check potential palindrome %d: %v\n", pal, err)
			}
			if ok && (x*y) > pal {
				pal = x * y
			}
		}
	}
	return pal, nil
}

// IsPalindrome returns a boolean indicating if the input is a palindrome or not; it converts the input to string, then slice of bytes, and ultimately reverses that slice; lastly, it tests if the input remains unchanged (and thus, is a palindrome) via comparing those byte slices as strings
func IsPalindrome(in int) (bool, error) {
	// test validity of input
	if in < 10 {
		return false, fmt.Errorf("invalid input: %d has less than 2 digits", in)
	}

	// determine if input is a palindromic integer
	s := strconv.Itoa(in)
	b := []byte(s)
	bRev := make([]byte, 0)
	for i := (len(b) - 1); i >= 0; i-- {
		bRev = append(bRev, b[i])
	}
	if string(b) == string(bRev) {
		return true, nil
	}
	return false, nil
}
