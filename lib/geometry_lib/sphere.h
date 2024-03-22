#pragma once
#include "geometry.h"
#include <memory>
#include "../operations_lib/operations.h"

/*

Contains initialization information for a Sphere. Has radius,
refractive index, luminosity and opacity. Refractive index controls
how the sphere refracts light, and opacity controls how transparent it is. Assume that all 
non-reflective and non-refractive spheres are diffuse.
*/

class Sphere : public Geometry
{
    Vec3 center;
    double radius;
    int opacity;       // on a scale of 1-100, where 100 is completely untransparent and 1 is most transparent
    double albedo = 0.18; // 0.18 is the average albedo for objects in the real world; this means that real world objects reflect around 18% of the light they receive
    

public:
    Sphere(Vec3 cent, double rad, double ref, int op, u_int32_t col, bool refle);

    double get_radius();
    int get_opacity();
    Vec3 get_center();


    // inherited methods
    shared_ptr<Vec3> calculate_poi(Ray incident_ray);
    bool get_reflective();
    double get_refractive_ind();
    u_int32_t get_color();
    Vec3 calculate_normal(Vec3 poi);
    Ray calculate_normal_ray(Vec3 poi);
    u_int32_t compute_reflected_color(Vec3 poi, Light light_src);
};