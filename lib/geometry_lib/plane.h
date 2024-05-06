#pragma once

#include <iostream>
#include <memory>
#include "../graphics_lib/ray.h" 
#include "geometry.h"

using std::shared_ptr;
class Plane : public Geometry {

    int plane_position; // corresponds to the z coordinate that the plane will be positioned at
    bool reflective = false;
    int reflective_ind = 800;
    Vec3 normal = {0, 0, plane_position + 1};
    

    public:

        Plane(int pos, u_int32_t col);
        int get_position();

        // inherited methods
        u_int32_t get_color();
        bool get_reflective();
        double get_refractive_ind();
        Vec3 calculate_normal(Vec3 poi);
        Ray calculate_normal_ray(Vec3 poi);
        u_int32_t compute_reflected_color(Vec3 poi, Light light_src);
        shared_ptr<Vec3> intersect(Ray ray);

};