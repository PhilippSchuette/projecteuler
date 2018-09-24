# unit tests for problem 1 solutions
import unittest
import problem1


class TestSolution(unittest.TestCase):
    def test_slow_division(self):
        self.assertEqual(problem1.slow_divisible(), 233168)
        self.assertNotEqual(problem1.slow_divisible(), 1)

    def test_fast_division(self):
        self.assertEqual(problem1.fast_divisible(), 233168)
        self.assertNotEqual(problem1.fast_divisible(), 1)


if __name__ == "__main__":
    unittest.main()
