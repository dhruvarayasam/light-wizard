#include "sphere.h"

Sphere::Sphere(double rad, double ref, int op, int col, int refle) : radius(rad), refractive_ind(ref), opacity(op), color(col), reflectivity(refle) {}

double Sphere::get_radius() {

    return this->radius;

}

double Sphere::get_refractive_ind() {

    return this->refractive_ind;

}

int Sphere::get_opacity() {

    return this->opacity;

}

int Sphere::get_color() {

    return this->color;

}

int Sphere::get_reflectivity() {
    return this->reflectivity;
}