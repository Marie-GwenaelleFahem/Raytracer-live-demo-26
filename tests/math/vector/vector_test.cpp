#include <catch2/catch_test_macros.hpp>
#include "Vector.h"

TEST_CASE("Vector addition", "[vector]")
{
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    Vector result = a + b;

    REQUIRE(result.x() == 5);
    REQUIRE(result.y() == 7);
    REQUIRE(result.z() == 9);
}

TEST_CASE("Vector subtraction", "[vector]")
{
    Vector a(-1, 4, 0);
    Vector b(-5, 2, 1);
    Vector result = a - b;

    REQUIRE(result.x() == 4);
    REQUIRE(result.y() == 2);
    REQUIRE(result.z() == -1);
}
