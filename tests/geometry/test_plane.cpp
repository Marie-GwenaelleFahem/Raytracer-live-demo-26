#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "colour/colour.h"
#include "geometry/plane.h"
#include "geometry/ray.h"
#include "material/material.h"
#include "math/vector.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("floor: ray hits at t=2, point (6,0,0), normal (0,1,0)", "[plane]") {
    Plane floor(Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    Ray ray(Vector(0, 8, 0), Vector(3, -4, 0));

    auto hit = floor.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(2.0, tolerance));
    requireVectorsEqual(hit->point, Vector(6, 0, 0));
    requireVectorsEqual(hit->normal, Vector(0, 1, 0));
    requireColoursEqual(hit->material.colour(), Colour(0, 1, 0));
}

TEST_CASE("slanted plane: ray hits at t=2, point (0,6,0), normal (0.6,0.8,0)", "[plane]") {
    Plane slant(Vector(8, 0, 0), Vector(3, 4, 0), Material(Colour(1, 0, 0)));
    Ray ray(Vector(-8, 0, 0), Vector(4, 3, 0));

    auto hit = slant.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(2.0, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 6, 0));
    requireVectorsEqual(hit->normal, Vector(0.6, 0.8, 0));
}

TEST_CASE("ray parallel to floor gives no hit", "[plane]") {
    Plane floor(Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    Ray ray(Vector(0, 8, 0), Vector(5, 0, 0));

    REQUIRE_FALSE(floor.hit(ray).has_value());
}

TEST_CASE("floor behind the ray gives no hit", "[plane]") {
    Plane floor(Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    Ray ray(Vector(0, 8, 0), Vector(3, 4, 0));

    REQUIRE_FALSE(floor.hit(ray).has_value());
}
