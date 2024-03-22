#pragma once
#include "plane.h"


Plane::Plane(int pos, u_int32_t col) {

    this->plane_position = pos;
    this->plane_color = col;

}

u_int32_t Plane::get_plane_color() {

    return this->plane_color;

}

int Plane::get_position() {

    return this->plane_position;

}



bool Plane::intersect(Ray incident_ray) {

    Vec3 p0 = {0, 0, this->get_position()};

    Vec3 plane_normal = this->get_normal();

    float denom = (incident_ray.get_dest() * plane_normal);

    if (denom != 0) {
        float numer = (plane_normal * p0) - (plane_normal *((incident_ray.get_orig())));

        float r = numer / denom;

        return (r >= 0);
    }

    return false;
}

Vec3 Plane::get_normal() {

    return this->normal;

}