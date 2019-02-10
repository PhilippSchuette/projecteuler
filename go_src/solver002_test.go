package geulerproject

import (
	"fmt"
	"testing"
)

type testCase2 struct {
	in   int
	want int
	err  error
}

func TestEvenFibs(t *testing.T) {
	cases := []testCase2{
		// test problem solution
		{
			in:   4e6,
			want: 4613732,
			err:  nil,
		},
		// test invalid input
		{
			in:   0,
			want: 0,
			err:  fmt.Errorf("error: limit should be greater than 1"),
		},
	}
	// iterate over test cases
	for _, c := range cases {
		got, err := EvenFibs(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("EvenFibs(%d) == %d, want %d\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("EvenFibs(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("EvenFibs(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
