#pragma once

#include "../graphics_lib/vec3.h"
#include "../graphics_lib/ray.h"
#include "../geometry_lib/sphere.h"

/*

This set of functions dictate the mathematical operations needed
to render the image. 

*/

namespace Operations {

    // rounds the value to the specified precision 
    double round_to (double value, double precision);

    // returns true if the given ray intersects with the given geometry
    bool intersect(Ray ray, Sphere sp);

    // This method returns true if a and b point in the same direction; i.e, if their components line up.
    bool verify_direct(const Ray& a, const Ray& b);
    
}