#include "render/trace.h"

Colour trace(const Ray& ray, const Scene& scene) {
    auto hit = scene.nearestHit(ray);
    if (!hit) {
        return Colour(0, 0, 0);
    }
    return hit->material.shade(hit->normal, scene.toLight());
}