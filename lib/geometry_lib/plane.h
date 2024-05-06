#pragma once

#include <iostream>
#include <memory>
#include "../graphics_lib/ray.h" 

using std::shared_ptr;
class Plane {

    int plane_position; // corresponds to the z coordinate that the plane will be positioned at
    u_int32_t plane_color; // hex coded color of the plane

    public:

        Plane(int pos, u_int32_t col);
        int get_position();
        u_int32_t get_plane_color();
        shared_ptr<Vec3> intersect(Ray ray);

};