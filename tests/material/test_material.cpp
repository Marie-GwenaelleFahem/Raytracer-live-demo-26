#include <catch2/catch_test_macros.hpp>

#include "colour/colour.h"
#include "material/material.h"
#include "math/vector.h"
#include "test_helpers.h"

TEST_CASE("material shading: light along the normal gives full colour", "[material]") {
    Material material(Colour(1, 0.5, 0));
    Vector normal(0, 0, -1);
    Vector toLight(0, 0, -1);

    requireColoursEqual(material.shade(normal, toLight), Colour(1, 0.5, 0));
}

TEST_CASE("material shading: light at 0.8 cosine gives 80% colour", "[material]") {
    Material material(Colour(1, 0.5, 0));
    Vector normal(0, 0, -1);
    Vector toLight(0.6, 0, -0.8);

    requireColoursEqual(material.shade(normal, toLight), Colour(0.8, 0.4, 0));
}

TEST_CASE("material shading: light perpendicular to normal gives black", "[material]") {
    Material material(Colour(1, 0.5, 0));
    Vector normal(0, 0, -1);
    Vector toLight(1, 0, 0);

    requireColoursEqual(material.shade(normal, toLight), Colour(0, 0, 0));
}

TEST_CASE("material shading: light from behind gives black, not negative", "[material]") {
    Material material(Colour(1, 0.5, 0));
    Vector normal(0, 0, -1);
    Vector toLight(0, 0, 1);

    requireColoursEqual(material.shade(normal, toLight), Colour(0, 0, 0));
}
