#include <catch2/catch.hpp>

#include "prime_utils.hpp"
#include "problem001.hpp"
#include "problem003.hpp"
#include "problem004.hpp"
#include "problem005.hpp"
#include "problem006.hpp"
#include "problem007.hpp"
#include "problem009.hpp"
#include "problem010.hpp"
#include "problem012.hpp"
#include "problem014.hpp"
#include "problem018and067.hpp"
#include "problem019.hpp"
#include "problem021.hpp"

TEST_CASE( "Testing multiples35_below (Problem 1)") {
   REQUIRE(multiples35_below(2) == std::vector<int>({}));
   REQUIRE(multiples35_below(5) == std::vector<int>({3}));
   REQUIRE(multiples35_below(10) == std::vector<int>({3, 5, 6, 9}));
}

TEST_CASE("Testing largest_prime_factor (Problem 3)") {
   REQUIRE(largest_prime_factor(2) == 2);
   REQUIRE(largest_prime_factor(12) == 3);
   REQUIRE(largest_prime_factor(13195) == 29);
   REQUIRE(largest_prime_factor(600851475143) == 6857);
}

TEST_CASE( "Testing prime_factors (Problem 3 and 12)") {
    REQUIRE(prime_factors(2) == std::make_pair(nvec({2}), nvec({1})));
    REQUIRE(prime_factors(3) == std::make_pair(nvec({3}), nvec({1})));
    REQUIRE(prime_factors(13) == std::make_pair(nvec({13}), nvec({1})));
    REQUIRE(prime_factors(14) == std::make_pair(nvec({2, 7}), nvec({1, 1})));
    REQUIRE(prime_factors(18) == std::make_pair(nvec({2, 3}), nvec({1, 2})));
}


TEST_CASE( "Testing is_palindrome (Problem 4)") {
    REQUIRE(is_palindrome(9009));
    REQUIRE(!is_palindrome(1234));
    REQUIRE(is_palindrome(12321));
}

TEST_CASE( "Testing smallest_evenly_divisible (Problem 5)") {
    REQUIRE(smallest_evenly_divisible(10) == 2520);
}

TEST_CASE( "Testing sum_of_squares and square_of_sum (Problem 6)") {
    REQUIRE(sum_of_squares(10) == 385);
    REQUIRE(square_of_sum(10) == 3025);
}

TEST_CASE( "Testing is_perfect_square (Problem 6)") {
    REQUIRE(is_perfect_square(4));
    REQUIRE(is_perfect_square(9));
    REQUIRE(is_perfect_square(16));
    REQUIRE(is_perfect_square(25));

    REQUIRE(!is_perfect_square(14));
    REQUIRE(!is_perfect_square(67));
}

TEST_CASE( "Testing Zeller's congruence (Problem 19)") {
    REQUIRE(zellers_congruence(1, 1, 1900) == 1);
    REQUIRE(zellers_congruence(17, 2, 2019) == 7);
    REQUIRE(zellers_congruence(2, 3, 2019) == 6);
}

TEST_CASE( "Testing prime_sum (Problem 10)") {
    REQUIRE(prime_sum(is_prime, 10) == 17);
}

TEST_CASE( "Testing nth_prime (Problem 7)") {
    REQUIRE(nth_prime(1) == 2);
    REQUIRE(nth_prime(2) == 3);
    REQUIRE(nth_prime(6) == 13);
    REQUIRE(nth_prime(10001) == 104743);
}

TEST_CASE( "Testing is_prime (Problem 7 and 10)") {
    REQUIRE(!is_prime(1));
    REQUIRE(is_prime(2));
    REQUIRE(!is_prime(4));
    REQUIRE(is_prime(7));
    REQUIRE(!is_prime(20));
}

TEST_CASE( "Testing num_divisors (Problem 12)") {
    REQUIRE(num_divisors(1) == 1);
    REQUIRE(num_divisors(2) == 2);
    REQUIRE(num_divisors(13) == 2);
    REQUIRE(num_divisors(14) == 4);
    REQUIRE(num_divisors(15) == 4);
    REQUIRE(num_divisors(21) == 4);
    REQUIRE(num_divisors(28) == 6);
}

TEST_CASE( "Testing triangle_number (Problem 12)") {
    REQUIRE(triangle_number(1) == 1);
    REQUIRE(triangle_number(2) == 3);
    REQUIRE(triangle_number(3) == 6);
    REQUIRE(triangle_number(4) == 10);
    REQUIRE(triangle_number(5) == 15);
}

TEST_CASE( "Testing collatz_len (Problem 14)") {
    REQUIRE(collatz_len(1) == 1);
    REQUIRE(collatz_len(2) == 2);
    REQUIRE(collatz_len(13) == 10);
}

TEST_CASE( "Testing Problem 18/67 fst and bruteforce solution") {
    REQUIRE(triangle_sum_bruteforce(getTriangle("../input_files/test018.txt")) == 23);
    REQUIRE(triangle_sum_bruteforce(getTriangle("../input_files/problem018.txt")) == 1074);
    REQUIRE(triangle_sum_fast(getTriangle("../input_files/test018.txt")) == 23);
    REQUIRE(triangle_sum_fast(getTriangle("../input_files/problem018.txt")) == 1074);
}

TEST_CASE( "Testing sum of divisors and amicable number test (Problem 21)") {
    REQUIRE(sum_of_divisors(220) == 284);
    REQUIRE(sum_of_divisors(284) == 220);
    REQUIRE(is_amicable(284) == std::make_pair(true, 220));
    REQUIRE(is_amicable(220) == std::make_pair(true, 284));
    REQUIRE(is_amicable(5) == std::make_pair(false, 1));
}

