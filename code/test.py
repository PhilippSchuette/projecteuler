# unit tests for all problem*.py files in ./code
import unittest
import unittest.mock

import problem1
import problem2
import problem3
import problem4
import problem5


class TestProblem1Solution(unittest.TestCase):
    def test_slow_division(self):
        self.assertEqual(problem1.slow_divisible(), 233168)
        self.assertNotEqual(problem1.slow_divisible(), 1)

    def test_fast_division(self):
        self.assertEqual(problem1.fast_divisible(), 233168)
        self.assertNotEqual(problem1.fast_divisible(), 1)


class TestProblem2Solution(unittest.TestCase):
    def test_slow_fibonacci(self):
        self.assertEqual(problem2.slow_fibonacci(10), 89)
        self.assertEqual(problem2.slow_fibonacci(1), 1)
        self.assertNotEqual(problem2.slow_fibonacci(10), 1)

    def test_fast_fibonacci(self):
        self.assertEqual(problem2.fast_fibonacci(1), 1)
        self.assertEqual(problem2.fast_fibonacci(4000000), 4613732)


class TestProblem3Solution(unittest.TestCase):
    def test_is_prime(self):
        self.assertTrue(problem3.is_prime(7))
        self.assertFalse(problem3.is_prime(20))

    def test_largest_prime_factor(self):
        self.assertEqual(problem3.largest_prime_factor(200000), 5)
        
            
class TestProblem4Solution(unittest.TestCase):
    def test_is_palindrome(self):
        self.assertTrue(problem4.is_palindrome(123454321))
        self.assertFalse(problem4.is_palindrome(74365))


class TestProblem5Solution(unittest.TestCase):
    def test_evenly_divisible(self):
        self.assertEqual(problem5.evenly_divisible(10), 2520)
        self.assertEqual(problem5.evenly_divisible(20), 232792560)


if __name__ == "__main__":
    unittest.main()
