#pragma once
#include "plane.h"


Plane::Plane(int pos, u_int32_t col) {

    this->plane_position = pos;
    this->plane_color = col;

}



shared_ptr<Vec3> Plane::intersect(Ray ray) {

    

}