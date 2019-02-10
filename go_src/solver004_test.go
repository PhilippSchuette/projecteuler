package geulerproject

import (
	"errors"
	"testing"
)

// test case for TestFindPalindrome
type testCase5 struct {
	in   int
	want int
	err  error
}

// test case for TestIsPalindrome
type testCase6 struct {
	in   int
	want bool
	err  error
}

func TestFindPalindrome(t *testing.T) {
	cases := []testCase5{
		// test problem solution
		{
			in:   3,
			want: 906609,
			err:  nil,
		},
		// test problem example
		{
			in:   2,
			want: 9009,
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
		got, err := FindPalindrome(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("FindPalindrome(%d) == %d, want %d\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FindPalindrome(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FindPalindrome(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

func TestIsPalindrome(t *testing.T) {
	cases := []testCase6{
		{
			in:   9009,
			want: true,
			err:  nil,
		},
		{
			in:   95059,
			want: true,
			err:  nil,
		},
		{
			in:   1234,
			want: false,
			err:  nil,
		},
		{
			in:   9,
			want: false,
			err:  errors.New("invalid input: 9 has less than 2 digits"),
		},
	}

	// iterate over test cases
	for _, c := range cases {
		got, err := IsPalindrome(c.in)

		// test similarity of expected and received value
		if got != c.want {
			t.Errorf("IsPalindrome(%d) == %v, want %v\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("IsPalindrome(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("IsPalindrome(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
