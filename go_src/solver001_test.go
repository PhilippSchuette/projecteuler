package geulerproject

import (
	"errors"
	"testing"
)

type testCase1 struct {
	in   []int
	want int
	err  error
}

func TestFindMultiples(t *testing.T) {
	// define test cases
	cases := []testCase1{
		// test example
		{
			in:   []int{3, 5, 0, 10},
			want: 23,
			err:  nil,
		},
		// test problem
		{
			in:   []int{3, 5, 0, 1000},
			want: 233168,
			err:  nil,
		},
		// test invalid input for search interval
		{
			in:   []int{3, 5, 0, 1},
			want: 0,
			err:  errors.New("0 and 1 too close to each other"),
		},
		// test invalid input for mult1 and mult2
		{
			in:   []int{-2, 1, 0, 10},
			want: 0,
			err:  errors.New("invalid input -2 and 1: must both be positive integers"),
		},
		{
			in:   []int{1, 1, 0, 10},
			want: 0,
			err:  errors.New("invalid input 1 and 1: specify two different, positive integers"),
		},
	}

	// run function on test cases
	for _, c := range cases {
		got, err := FindMultiples(c.in[0], c.in[1], c.in[2], c.in[3])

		// test similarity of expected and received values
		if got != c.want {
			t.Errorf("FindMultiples(%d, %d, %d, %d) == %d, want %d\n", c.in[0], c.in[1], c.in[2], c.in[3], got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FindMultiples(%d, %d, %d, %d) returned error %v, want %v\n", c.in[0], c.in[1], c.in[2], c.in[3], err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FindMultiples(%d, %d, %d, %d) returned error %v, want %v\n", c.in[0], c.in[1], c.in[2], c.in[3], err, c.err)
			}
		}
	}
}
