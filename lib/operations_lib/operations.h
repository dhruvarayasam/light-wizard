#pragma once

#include "../graphics_lib/vec3.h"
#include "../graphics_lib/ray.h"
#include "../geometry_lib/sphere.h"

/*

This set of functions dictate the mathematical operations needed
to render the image. 

*/

namespace Operations {

    double round_to (double value, double precision);
    bool intersect(Ray ray, Sphere sp);
    
}