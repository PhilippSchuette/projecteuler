#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() 
#include <catch2/catch.hpp>
#include "prime_utils.hpp"
#include "problem007.hpp"
#include "problem010.hpp"
#include "problem019.hpp"

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

