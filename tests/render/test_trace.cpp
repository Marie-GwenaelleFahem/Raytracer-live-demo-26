#include <catch2/catch_test_macros.hpp>

#include <memory>

#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "material/material.h"
#include "math/vector.h"
#include "render/trace.h"
#include "scene/scene.h"
#include "test_helpers.h"

TEST_CASE("trace: sun behind eye, centre hit, gives full red", "[trace]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    requireColoursEqual(trace(ray, scene), Colour(1, 0, 0));
}

TEST_CASE("trace: sun at 0.8 cosine gives 0.8 red", "[trace]") {
    Scene scene(Vector(0.6, 0, -0.8));
    scene.add(std::make_unique<Sphere>(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    requireColoursEqual(trace(ray, scene), Colour(0.8, 0, 0));
}

TEST_CASE("trace: side hit with sun behind eye gives 0.8 red", "[trace]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    requireColoursEqual(trace(ray, scene), Colour(0.8, 0, 0));
}

TEST_CASE("trace gives black when the ray misses the sphere", "[trace]") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));
    Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    requireColoursEqual(trace(ray, scene), Colour(0, 0, 0));
}