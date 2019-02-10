package geulerproject

import "fmt"

// FindMultiples takes four integer parameters. mult1 and mult2 specify which multiples should be taken into consideration when calculating the final sum. start and stop specify the inteval over which the algorithm should iterate (e.g. 0 & 1000 to start at 0 and look at all integers excluding 1000. The function returns the final sum and an error (latter needs to be implemented for more robust execution)
func FindMultiples(mult1, mult2, start, stop int) (int, error) {
	// test validity of values for 'start' and 'stop'
	if !(stop > (start + 1)) {
		return 0, fmt.Errorf("%d and %d too close to each other", start, stop)
	}

	// test validity of values for mult1 and mult2
	switch {
	case mult1 < 0 || mult2 < 0:
		return 0, fmt.Errorf("invalid input %d and %d: must both be positive integers", mult1, mult2)
	case mult1 == mult2:
		return 0, fmt.Errorf("invalid input %d and %d: specify two different, positive integers", mult1, mult2)
	}

	// declare a counter variable and iterate over the given interval (start, stop]
	var sum int
	for i := start; i < stop; i++ {
		switch {
		case (i % mult1) == 0:
			sum += i
		case (i % mult2) == 0:
			sum += i
		default:
			// i is not a multiple of either mult1 or mult2, so continue looping
		}
	}
	return sum, nil
}
