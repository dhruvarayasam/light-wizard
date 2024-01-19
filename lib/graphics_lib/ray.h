#pragma once
#include <iostream>
#include "vec3.h"

class Ray {

    Vec3 orig;
    Vec3 dest; // should be normalized
    int color; // represented in hexadecimal format. 

    public:
        Ray();
        Ray(Vec3 o, Vec3 d); // normalize destination vector in constructor

        // operator overloads
        friend std::ostream& operator << (std::ostream& os, const Ray& a);

};

