package geulerproject

import (
	"errors"
	"math"
	"testing"
)

type testCase8 struct {
	in   int
	want []float64
	err  error
}

var cases = []testCase8{
	// test very large input
	{
		in:   100000,
		want: []float64{3.3333833335e+14, 2.50005000025e+19},
		err:  nil,
	},
	// test example case
	{
		in:   10,
		want: []float64{385, 3025},
		err:  nil,
	},
	// test problem case
	{
		in:   100,
		want: []float64{338350, 2.55025e+07},
		err:  nil,
	},
	// test invalid input
	{
		in:   -5,
		want: []float64{0, 0},
		err:  errors.New("invalid input: -5 is less than 1"),
	},
}

func TestSumOfSquares(t *testing.T) {
	// iterate over test cases for slow solution
	for _, c := range cases {
		got, err := SumOfSquares(c.in)

		// test similarity of expected and received value
		if got != c.want[0] {
			t.Errorf("SumOfSquares(%d) == %v, want %v\n", c.in, got, c.want[0])
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("SumOfSquares(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("SumOfSquares(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

func TestSquareOfSums(t *testing.T) {
	// iterate over test cases for slow solution
	for _, c := range cases {
		got, err := SquareOfSums(c.in)

		// test similarity of expected and received value
		if got != c.want[1] {
			t.Errorf("SquareOfSums(%d) == %v, want %v\n", c.in, got, c.want[1])
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("SquareOfSums(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("SquareOfSums(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

func TestFastSumOfSquares(t *testing.T) {
	// iterate over test cases for fast solution
	for _, c := range cases {
		got, err := FastSumOfSquares(float64(c.in))

		// test similarity of expected and received value
		if math.Round(got) != c.want[0] {
			t.Errorf("FastSumOfSquares(%d) == %v, want %v\n", c.in, math.Round(got), c.want[0])
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FastSumOfSquares(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FastSumOfSquares(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}

func TestFastSquareOfSums(t *testing.T) {
	// iterate over test cases for slow solution
	for _, c := range cases {
		got, err := FastSquareOfSums(float64(c.in))

		// test similarity of expected and received value
		if got != c.want[1] {
			t.Errorf("FastSquareOfSums(%d) == %v, want %v\n", c.in, got, c.want[1])
		}

		// if no error is returned, test if none is expected
		if err == nil && c.err != nil {
			t.Errorf("FastSquareOfSums(%d) returned error %v, want %v\n", c.in, err, c.err)
		}

		// if error is returned, test if an error is expected
		if err != nil {
			if err.Error() != c.err.Error() {
				t.Errorf("FastSquareOfSums(%d) returned error %v, want %v\n", c.in, err, c.err)
			}
		}
	}
}
