package geulerproject

import (
	"errors"
	"sort"
	"testing"
)

type testCase11 struct {
	in   float64
	want []float64
	err  error
}

func TestPythagoreanTriplet(t *testing.T) {
	cases := []testCase11{
		// test example
		{
			in:   12,
			want: []float64{3, 4, 5},
			err:  nil,
		},
		// test problem solution
		{
			in:   1000,
			want: []float64{200, 375, 425},
			err:  nil,
		},
		// test case without a valid solution
		{
			in:   50,
			want: []float64{0, 0, 0},
			err:  errors.New("cannot find pythagorean triplet with sum: 50"),
		},
		// test invalid input
		{
			in:   -5,
			want: []float64{0, 0, 0},
			err:  errors.New("invalid input: -5 is smaller than minimal input of 3"),
		},
	}

	// iterate over test cases
	for _, c := range cases {
		r1, r2, r3, err := PythagoreanTriplet(c.in)
		got := []float64{r1, r2, r3}

		// output is not always sorted
		sort.Float64s(got)

		// test similarity of expected and received value
		if !isEqualSlice(got, c.want) {
			t.Errorf("PythagoreanTriplet(%v) == %v, want %v\n", c.in, got, c.want)
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("PythagoreanTriplet(%v) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			// if c.err is nil, print wanted and received error
			// else if an error is wanted and received but error messages are not the same
			// print wanted and received error
			if c.err == nil {
				t.Errorf("PythagoreanTriplet(%v) returned error %v, want %v\n", c.in, err, c.err)
			} else if err.Error() != c.err.Error() {
				t.Errorf("PythagoreanTriplet(%v) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

// func isEqualSlice returns true if the lenght of the input slices is identical
// and all elements of the input slices are identical, too
func isEqualSlice(a, b []float64) bool {
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
