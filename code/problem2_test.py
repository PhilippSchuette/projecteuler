# unit tests for problem 2 solutions
import unittest

import problem2


class TestSolution(unittest.TestCase):
    def test_fibonacci(self):
        self.assertEqual(problem2.fibonacci(10), 1)
        self.assertNotEqual(problem2.fibonacci(10), 1)


if __name__ == "__main__":
    unittest.main()
