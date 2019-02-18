#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() 
#include <catch2/catch.hpp>
#include "problem019.hpp"

TEST_CASE( "Testing Zeller's congruence") {
    REQUIRE(zellers_congruence(1, 1, 1900) == 1);
    REQUIRE(zellers_congruence(17, 2, 2019) == 7);
}

