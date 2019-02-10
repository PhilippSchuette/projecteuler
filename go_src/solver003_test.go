package geulerproject

import (
	"errors"
	"testing"
)

// test case struct for TestLargestPrimeFactor
type testCase3 struct {
	in   int
	want int
	err  error
}

// test case struct for IsPrimeNumber
type testCase4 struct {
	in   int
	want bool
	err  error
}

func TestLargestPrimeFactor(t *testing.T) {
	cases := []testCase3{
		// test problem example
		{
			in:   13195,
			want: 29,
			err:  nil,
		},
		// test problem solution
		{
			in:   600851475143,
			want: 6857,
			err:  nil,
		},
		// test invalid input
		{
			in:   -1,
			want: 0,
			err:  errors.New("invalid input: -1 is less than 1"),
		},
		// test edge cases
		{
			in:   1,
			want: 1,
			err:  nil,
		},
		{
			in:   2,
			want: 2,
			err:  nil,
		},
		// test prime number as input
		{
			in:   11,
			want: 11,
			err:  nil,
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := LargestPrimeFactor(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("LargestPrimeFactor(%d) == %d, want %d\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("LargestPrimeFactor(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("LargestPrimeFactor(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

func TestIsPrimeNumber(t *testing.T) {
	cases := []testCase4{
		// test invalid input
		{
			in:   -5,
			want: false,
			err:  errors.New("invalid input: -5 is less than 1"),
		},
		// test edge case
		{
			in:   1,
			want: false,
			err:  nil,
		},
		// test non-prime number
		{
			in:   4,
			want: false,
			err:  nil,
		},
		// test prime number
		{
			in:   7,
			want: true,
			err:  nil,
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := IsPrimeNumber(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("IsPrimeNumber(%d) == %v, want %v\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("IsPrimeNumber(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("IsPrimeNumber(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
