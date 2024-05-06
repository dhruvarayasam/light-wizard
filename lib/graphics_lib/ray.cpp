#include <iostream>
#include "ray.h"

// constructors

Ray :: Ray() : orig (Vec3 {0, 0, 0}), dest (Vec3 {1, 1, 1}) {}

Ray :: Ray(Vec3 o, Vec3 d) : orig (o), dest (d) {}

// overloads

std::ostream& operator<< (std::ostream& os, const Ray& a) {

    os << "Origin: " << a.orig << "\nDestination: " << a.dest;

    return os;

}

Vec3 Ray::get_orig() {

    return this->orig;

}

Vec3 Ray::get_dest() {

    return this->dest;

}

int Ray::get_color() {

    return this->color;

}


