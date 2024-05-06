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



shared_ptr<Vec3> Plane::intersect(Ray ray) {

    

}