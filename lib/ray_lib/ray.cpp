#include <iostream>
#include "ray.h"


Ray::Ray() : orig(Point {0, 0, 0}), dest(Point {1, 1, 1}) {}


Ray::Ray(const Point& a, const Point& b) : orig(a), dest(b) {}

std::ostream& operator<< (std::ostream& os, const Ray& ray) {

    os << "Origin: " << ray.orig << "\n" << "Dest: " << ray.dest << std::endl;

    return os;

}

