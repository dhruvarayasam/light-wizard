#include "sphere.h"

Sphere::Sphere() : radius(1), refractive_ind(0), luminosity(0), opacity(1) {}

Sphere::Sphere(double rad, double ref, double lum, int op) : radius(rad), refractive_ind(ref), luminosity(lum), opacity(op) {}

