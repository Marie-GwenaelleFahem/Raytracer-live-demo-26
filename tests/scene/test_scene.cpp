#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <memory>

#include "colour/colour.h"
#include "geometry/plane.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "scene/scene.h"
#include "test_helpers.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("scene normalises toLight", "[scene]") {
    Scene scene(Vector(0, 3, -4));

    requireVectorsEqual(scene.toLight(), Vector(0, 0.6, -0.8));
}

TEST_CASE("scene: near plane in front of sphere wins", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(Vector(0, 0, 2), Vector(0, 0, -1), Material(Colour(0, 0, 1))));

    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    auto hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(3.0, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(0, 0, 1));
}

TEST_CASE("scene: sphere in front of far plane wins", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(Vector(0, 0, 20), Vector(0, 0, -1), Material(Colour(0, 0, 1))));

    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    auto hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, WithinAbs(5.0, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("scene: ray that hits nothing returns no hit", "[scene]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));

    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    REQUIRE_FALSE(scene.nearestHit(ray).has_value());
}
