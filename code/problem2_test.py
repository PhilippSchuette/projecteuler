# unit tests for problem 2 solutions
import unittest

import problem2


class TestSolution(unittest.TestCase):
    def test_slow_fibonacci(self):
        self.assertEqual(problem2.slow_fibonacci(10), 89)
        self.assertNotEqual(problem2.slow_fibonacci(10), 1)


if __name__ == "__main__":
    unittest.main()
