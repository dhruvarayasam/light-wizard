#pragma once
#include <iostream>
#include "vec3.h"


/*
The Ray class is a wrapper for the O+tD format
for representing vectors with an origin and direction vector.
Parameter is assumed to be 1. Direction vector will be normalized
by default.
*/
class Ray {

    Vec3 orig;
    Vec3 dest; // should be normalized
    int color; // represented in hexadecimal format. 

    public:
        Ray();
        Ray(Vec3 o, Vec3 d); // normalize destination vector in constructor

        // operator overloads
        friend std::ostream& operator << (std::ostream& os, const Ray& a);

        // class methods

        Vec3 get_orig();
        Vec3 get_dest();
        int get_color();

};

