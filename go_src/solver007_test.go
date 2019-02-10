package geulerproject

import (
	"errors"
	"testing"
)

type testCase9 struct {
	in   int
	want int
	err  error
}

func TestFindPrimeNumber(t *testing.T) {
	cases := []testCase9{
		// test problem
		{
			in:   10001,
			want: 104743,
			err:  nil,
		},
		// test example
		{
			in:   6,
			want: 13,
			err:  nil,
		},
		// test invalid input
		{
			in:   -5,
			want: 0,
			err:  errors.New("invalid input: -5 is less than 1"),
		},
		{
			in:   1,
			want: 2,
			err:  nil,
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := FindPrimeNumber(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("FindPrimeNumber(%d) == %d, want %d\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FindPrimeNumber(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FindPrimeNumber(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
