package geulerproject

import (
	"errors"
	"testing"
)

type testCase7 struct {
	in   int
	want int
	err  error
}

func TestEvenlyDivisible(t *testing.T) {
	cases := []testCase7{
		{
			in:   10,
			want: 2520,
			err:  nil,
		},
		{
			in:   20,
			want: 232792560,
			err:  nil,
		},
		{
			in:   -5,
			want: 0,
			err:  errors.New("invalid input: -5 is less than 1"),
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := EvenlyDivisible(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("EvenlyDivisible(%d) == %d, want %d\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("EvenlyDivisible(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("EvenlyDivisible(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
