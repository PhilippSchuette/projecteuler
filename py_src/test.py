# unit tests for all problem00*.py files in ./code
import unittest
import unittest.mock

import problem001
import problem002
import problem003
import problem004
import problem005
import problem006
import problem007


class TestProblem001Solution(unittest.TestCase):
    def test_slow_division(self):
        self.assertEqual(problem001.slow_divisible(), 233168)
        self.assertNotEqual(problem001.slow_divisible(), 1)

    def test_fast_division(self):
        self.assertEqual(problem001.fast_divisible(), 233168)
        self.assertNotEqual(problem001.fast_divisible(), 1)


class TestProblem002Solution(unittest.TestCase):
    def test_slow_fibonacci(self):
        self.assertEqual(problem002.slow_fibonacci(10), 89)
        self.assertEqual(problem002.slow_fibonacci(1), 1)
        self.assertNotEqual(problem002.slow_fibonacci(10), 1)

    def test_fast_fibonacci(self):
        self.assertEqual(problem002.fast_fibonacci(1), 1)
        self.assertEqual(problem002.fast_fibonacci(4000000), 4613732)


class TestProblem003Solution(unittest.TestCase):
    def test_is_prime(self):
        self.assertTrue(problem003.is_prime(7))
        self.assertFalse(problem003.is_prime(20))

    def test_largest_prime_factor(self):
        self.assertEqual(problem003.largest_prime_factor(200000), 5)


class TestProblem004Solution(unittest.TestCase):
    def test_is_palindrome(self):
        self.assertTrue(problem004.is_palindrome(123454321))
        self.assertFalse(problem004.is_palindrome(74365))


class TestProblem005Solution(unittest.TestCase):
    def test_evenly_divisible(self):
        self.assertEqual(problem005.evenly_divisible(10), 2520)
        self.assertEqual(problem005.evenly_divisible(20), 232792560)


class TestProblem006Solution(unittest.TestCase):
    def test_calc_sums(self):
        self.assertEqual(problem006.calc_sums(1, 100), 25164150)


class TestProblem007Solution(unittest.TestCase):
    def test_nth_prime(self):
        self.assertEqual(problem007.nth_prime(1), 2)
        self.assertEqual(problem007.nth_prime(2), 3)
        self.assertEqual(problem007.nth_prime(6), 13)
        self.assertNotEqual(problem007.nth_prime(6), 14)


if __name__ == "__main__":
    unittest.main()
