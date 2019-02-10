package geulerproject

import (
	"fmt"
	"math"
)

// PythagoreanTriplet finds the pythagorean triplet (see `main/problem9.go`) takes
// a float64 n as its input and returns a, b, c  for which a + b + c = n
// or an error; the output of PythagoreanTriplet is not sorted!
func PythagoreanTriplet(n float64) (float64, float64, float64, error) {
	// test validity of input
	if n < 3 {
		return 0, 0, 0, fmt.Errorf("invalid input: %v is smaller than minimal input of 3", n)
	}

	// an outer loop checks variable whereas an inner loop checks all variables b
	// for which 0 < b < a; negative numbers are not allow and not checked
	a := 1.0 /* need float64 for math. */
	for {
		// loop over all possible b's
		for b := 1.0; b < a; b++ {
			// stop condition
			if a > n {
				return 0, 0, 0, fmt.Errorf("cannot find pythagorean triplet with sum: %v", n)
			}
			if (a + b + (math.Sqrt(math.Pow(a, 2) + math.Pow(b, 2)))) == n {
				return a, b, math.Sqrt(math.Pow(a, 2) + math.Pow(b, 2)), nil
			}
		}
		a++
	}
}
