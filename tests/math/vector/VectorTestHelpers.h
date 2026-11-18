#pragma once

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "Vector.h"

using Catch::Matchers::WithinAbs;

static constexpr double tolerance = 1e-9;

inline void requireVectorsEqual(const Vector& a, const Vector& b)
{
    REQUIRE_THAT(a.x(), WithinAbs(b.x(), tolerance));
    REQUIRE_THAT(a.y(), WithinAbs(b.y(), tolerance));
    REQUIRE_THAT(a.z(), WithinAbs(b.z(), tolerance));
}
