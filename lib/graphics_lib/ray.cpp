#include <iostream>
#include "ray.h"

// constructors

Ray :: Ray() : orig (Vec3 {0, 0, 0}), dest (Vec3 {1, 1, 1}) {}

Ray :: Ray(Vec3 o, Vec3 d) : orig (o), dest (d.normalize()) {}

// overloads

std::ostream& operator<< (std::ostream& os, const Ray& a) {

    os << "Origin: " << a.orig << "\nDestination: " << a.dest;

    return os;

}



