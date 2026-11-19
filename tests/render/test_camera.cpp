#include <catch2/catch_test_macros.hpp>

#include <string>
#include <vector>

#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "image/image.h"
#include "material/material.h"
#include "math/vector.h"
#include "render/camera.h"
#include "test_helpers.h"

// This morning's tests: the one pixel of a 1 by 1 image is the centre of the screen.
TEST_CASE("in a 1 by 1 image, the ray goes from the eye to the screen centre", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);

    Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("in a 1 by 1 image, the ray has direction screen centre - eye", "[camera]") {
    Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);

    Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}

// The board's 5 by 3 grid, on a screen 5 wide: one pixel is 1 across.
TEST_CASE("the centre pixel's ray goes straight ahead", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);

    Ray ray = camera.rayThroughPixel(2, 1, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("the top-right pixel's ray goes right and up", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);

    Ray ray = camera.rayThroughPixel(4, 0, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(2, 1, 1));
}

TEST_CASE("the bottom-left pixel's ray goes left and down", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);

    Ray ray = camera.rayThroughPixel(0, 2, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(-2, -1, 1));
}

TEST_CASE("render gives an image of the size asked for", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    Sphere sphere(Vector(0, 0, 6), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0, 0, -1);

    Image image = camera.render(sphere, toLight, 5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);
}

TEST_CASE("render: centre pixel is full red, neighbours are 0.8 red", "[camera]") {
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    Sphere sphere(Vector(0, 0, 6), 5, Material(Colour(1, 0, 0)));
    Vector toLight(0, 0, -1);

    Image image = camera.render(sphere, toLight, 5, 3);

    // Centre pixel (2,1): normal (0,0,-1), toLight (0,0,-1) → cosine 1 → full red
    requireColoursEqual(image.pixel(2, 1), Colour(1, 0, 0));
    // Neighbours (1,1),(3,1),(2,0),(2,2): cosine 0.8 → 0.8 red
    requireColoursEqual(image.pixel(1, 1), Colour(0.8, 0, 0));
    requireColoursEqual(image.pixel(3, 1), Colour(0.8, 0, 0));
    requireColoursEqual(image.pixel(2, 0), Colour(0.8, 0, 0));
    requireColoursEqual(image.pixel(2, 2), Colour(0.8, 0, 0));
    // Corners and far pixels are black
    requireColoursEqual(image.pixel(0, 0), Colour(0, 0, 0));
    requireColoursEqual(image.pixel(4, 0), Colour(0, 0, 0));
    requireColoursEqual(image.pixel(0, 2), Colour(0, 0, 0));
    requireColoursEqual(image.pixel(4, 2), Colour(0, 0, 0));
}