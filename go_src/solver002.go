package geulerproject

import "errors"

// EvenFibs finds all fibonacci numbers up to a certain n and returns the sum of all even terms in this sequence
// Note: an easier (and faster) solution takes every third fibonacci sequence term into account (because every third one is even!)
func EvenFibs(limit int) (int, error) {
	// check validity of input
	if limit < 1 {
		return 0, errors.New("error: limit should be greater than 1")
	}

	// find fibonacci sequence terms up to limit and append them to a slice
	seq := make([]int, 0)
	for i := 1; ; i++ {
		f := fibs(i)
		if f > limit {
			break
		}
		seq = append(seq, f)
	}

	// iterate over slice and sum even terms up
	var sum int
	for _, t := range seq {
		if (t % 2) == 0 {
			sum += t
		}
	}
	return sum, nil
}

// fibs returns the n'th term of the fibonacci sequence
func fibs(n int) int {
	// find fibonacci sequence recursively
	switch n {
	case 1:
		return 1
	case 2:
		return 2
	default:
		return fibs(n-1) + fibs(n-2)
	}
}
