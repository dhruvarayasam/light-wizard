#pragma once

#include <iostream>
#include <memory>
#include "ray.h" 

using std::shared_ptr;

// Plane class contains the y position that the plane is positioned at and the color of the plane itself.
class Plane {

    int plane_position = 0; // corresponds to the z coordinate that the plane will be positioned at
    u_int32_t plane_color; // hex coded color of the plane
    Vec3 normal = {0, 0, plane_position+1};

    public:

        Plane(int pos, u_int32_t col);
        int get_position();
        u_int32_t get_plane_color();
        bool intersect(Ray incident_ray);
        Vec3 get_normal();

};