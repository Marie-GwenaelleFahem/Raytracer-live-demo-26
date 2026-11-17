#include <catch2/catch_test_macros.hpp>
#include "Vector.h"

TEST_CASE("Vector addition", "[vector]")
{
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    Vector result = a.add(b);

    REQUIRE(result.getX() == 5);
    REQUIRE(result.getY() == 7);
    REQUIRE(result.getZ() == 9);
}

TEST_CASE("Vector subtraction", "[vector]")
{
    Vector a(-1, 4, 0);
    Vector b(-5, 2, 1);
    Vector result = a.subtract(b);

    REQUIRE(result.getX() == 4);
    REQUIRE(result.getY() == 2);
    REQUIRE(result.getZ() == -1);
}
