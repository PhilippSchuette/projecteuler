#include <catch2/catch.hpp>

#include "prime_utils.hpp"
#include "problem001.hpp"
#include "problem004.hpp"
#include "problem005.hpp"
#include "problem006.hpp"
#include "problem007.hpp"
#include "problem009.hpp"
#include "problem010.hpp"
#include "problem014.hpp"
#include "problem019.hpp"

TEST_CASE( "Testing multiples35_below (Problem 1)") {
   REQUIRE(multiples35_below(2) == std::vector<int>({}));
   REQUIRE(multiples35_below(5) == std::vector<int>({3}));
   REQUIRE(multiples35_below(10) == std::vector<int>({3, 5, 6, 9}));
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

TEST_CASE( "Testing collatz_len (Problem 14)") {
    REQUIRE(collatz_len(1) == 1);
    REQUIRE(collatz_len(2) == 2);
    REQUIRE(collatz_len(13) == 10);
}
