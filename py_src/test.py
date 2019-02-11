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
import problem008
import problem013


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

    def test_check_prime(self):
        self.assertTrue(problem005.check_prime(13))
        self.assertFalse(problem005.check_prime(14))

    def test_prime_list(self):
        self.assertListEqual(problem005.prime_list(6),
                             [2, 3, 5])

    def test_lcm(self):
        self.assertEqual(problem005.lcm(20), 232792560)


class TestProblem006Solution(unittest.TestCase):
    def test_calc_sums(self):
        self.assertEqual(problem006.calc_sums(1, 100), 25164150)


class TestProblem007Solution(unittest.TestCase):
    def test_nth_prime(self):
        self.assertEqual(problem007.nth_prime(1), 2)
        self.assertEqual(problem007.nth_prime(2), 3)
        self.assertEqual(problem007.nth_prime(6), 13)
        self.assertNotEqual(problem007.nth_prime(6), 14)


class TestProblem008Solution(unittest.TestCase):
    def test_bruteforce_product(self):
        self.testList = [1, 2, 8, 2, 2, 2, 1, 9, 1]
        self.assertEqual(problem008.bruteforce_product(self.testList, 2), 16)

    def test_faster_product(self):
        self.testList = [1, 2, 8, 2, 2, 2, 1, 9, 1]
        self.assertEqual(problem008.faster_product(self.testList, 2), 16)

class TestProblem013Solution(unittest.TestCase):
    def test_sum_numbers(self):
        self.assertEqual(problem013.sum_numbers([123, 100, 400]), 623)

if __name__ == "__main__":
    unittest.main()
