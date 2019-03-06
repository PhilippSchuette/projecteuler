#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() 

#include <catch2/catch.hpp>

// The actual tests are in tests.cpp, this file just makes sure that we
// don't have to recompile Catch everytime we add a new test case, 
// for details see
// https://github.com/catchorg/Catch2/blob/master/docs/slow-compiles.md
