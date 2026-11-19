#include <catch2/catch_test_macros.hpp>

#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "render/trace.h"
#include "test_helpers.h"

TEST_CASE("trace: sun behind eye, centre hit, gives full red", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0, 0, -1);

    requireColoursEqual(trace(ray, sphere, toLight), Colour(1, 0, 0));
}

TEST_CASE("trace: sun at 0.8 cosine gives 0.8 red", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0.6, 0, -0.8);

    requireColoursEqual(trace(ray, sphere, toLight), Colour(0.8, 0, 0));
}

TEST_CASE("trace: side hit with sun behind eye gives 0.8 red", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0, 0, -1);

    requireColoursEqual(trace(ray, sphere, toLight), Colour(0.8, 0, 0));
}

TEST_CASE("trace gives black when the ray misses the sphere", "[trace]") {
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0, 0, -1);

    requireColoursEqual(trace(ray, sphere, toLight), Colour(0, 0, 0));
}