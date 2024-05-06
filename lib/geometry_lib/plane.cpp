#include "plane.h"

Plane::Plane(int pos, u_int32_t col) {

    this->plane_position = pos;
    this->color = col;
    this->normal = Vec3 {0, 0, this->plane_position+1};

}

u_int32_t Plane::get_color() {

    return this->color;

}

int Plane::get_position() {

    return this->plane_position;

}

bool Plane::get_reflective() {

    return this->reflective; 

}

double Plane::get_refractive_ind() {
    return this->refractive_ind;
}

Vec3 Plane::calculate_normal(Vec3 poi) {
    return Vec3{0, 0, 0};
}

Ray Plane::calculate_normal_ray(Vec3 poi) {

    return Ray{Vec3{0, 0, 0}, Vec3{0, 0, 0}};

}

u_int32_t Plane::compute_reflected_color(Vec3 poi, Light light_src) {
    return 0;
}

shared_ptr<Vec3> Plane::intersect(Ray ray) {

    float denom = this->normal * ray.get_dest();
    Vec3 p0 = {0, 0, this->get_position()};
    Vec3 l0 = ray.get_orig();
    Vec3 l = ray.get_dest();
    Vec3 n = this->normal;
    double t;

        Vec3 p0l0 = p0 - l0;
        t = (p0l0 * n) / denom;

        if (t > 0) {

            return std::make_shared<Vec3>(l0 + (t * l));

        } 

    return NULL;

}