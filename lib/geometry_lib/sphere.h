#pragma once
#include "geometry.h"
#include <memory>
#include "../operations_lib/operations.h"

/*

Contains initialization information for a Sphere. Has radius,
refractive index, luminosity and opacity. Refractive index controls
how the sphere refracts light, luminosity controls how bright the object is (irrespective of color)
and opacity controls how transparent it is.

Luminosity and opacity are on a scale from 0 to 1.

*/

class Sphere : public Geometry
{
    Vec3 center;
    double radius;
    int opacity;       // on a scale of 1-100, where 100 is completely untransparent and 1 is most transparent
    

public:
    Sphere(Vec3 cent, double rad, double ref, int op, u_int32_t col, bool refle);

    double get_radius();
    int get_opacity();


    // inherited methods
    shared_ptr<Vec3> intersect(Ray ray);
    bool get_reflective();
    double get_refractive_ind();
    u_int32_t get_color();
    Vec3 calculate_normal(Vec3 poi);
    Ray calculate_normal_ray(Vec3 poi);
};