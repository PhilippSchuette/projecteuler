package geulerproject

import (
	"errors"
	"testing"
)

type testCase10 struct {
	in   int
	want int
	err  error
}

func TestFindGreatestProduct(t *testing.T) {
	cases := []testCase10{
		// test example
		{
			in:   4,
			want: 5832,
			err:  nil,
		},
		// test problem
		{
			in:   13,
			want: 23514624000,
			err:  nil,
		},
		// test large input
		{
			in:   25,
			want: 94810963968000000,
			err:  nil,
		},
		// test invalid input
		{
			in:   -5,
			want: 0,
			err:  errors.New("invalid input: -5 is less than 1"),
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := FindGreatestProduct(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("FindGreatestProduct(%d) == %v, want %v\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FindGreatestProduct(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FindGreatestProduct(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
