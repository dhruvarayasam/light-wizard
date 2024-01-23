#include "sphere.h"
#include <cmath>

using std::shared_ptr;
using std::make_shared;

Sphere::Sphere(Vec3 cent, double rad, double ref, int op, u_int32_t col, bool refle) : radius(rad), opacity(op), center(cent) {

    this->reflective = refle;
    this->refractive_ind = ref;
    this->color = col;

}

double Sphere::get_radius()
{

    return this->radius;
}

int Sphere::get_opacity()
{

    return this->opacity;
}

u_int32_t Sphere::get_color()
{

    return this->color;
}

shared_ptr<Vec3> Sphere::intersect(Ray ray)
{

    /*

    CALCULATION FOR INTERSECTION

    We represent a ray in the format O + tD. t is a parameter and
    O and D are origin and destination. The format for representing a circle in 3D
    is x^2+y^2+z^2 = R^2. This can be denoted as P^2 - R^2 = 0, where P is a 3D vector.
    P can be substituted with O + tD. Simplifying, this gives us:

    D^2*t^2 + 2ODt + O^2 - R^2 = 0. To solve for our points of intersection,
    we solve for the discriminant.

    If discriminant is >0, there are two intersections.
    If discriminant is =0, there is 1 intersection.
    If discriminant is <0, there are no intersections.

    This formula is easily modified for cases where spheres are not centered exactly
    at the origin.

    */

    int rad = this->radius;
    Vec3 center = this->center;

    Vec3 dest = ray.get_dest();
    Vec3 origin = ray.get_orig();
    int color = ray.get_color();

    // coefficients for equation
    double a = dest * dest;
    double b = 2 * dest * (origin - center);
    double c = (origin * origin) - rad;

    double discrim = (b * b) - (4 * (a * c));

    discrim = Operations::round_to(discrim);

    // now calculate parameter based on discriminant

    double t0;
    double t1;

    double valid_param = MAXFLOAT;
    bool param_found = false;

    if (discrim > 0)
    {

        t0 = (-b + sqrt(discrim)) / (2 * a);
        t1 = (-b - sqrt(discrim)) / (2 * a);

        if (t1 > 0 && t1 > 0)
        {

            if (t1 > t0)
                valid_param = t1;
            else if (t0 > t1)
                valid_param = t0;
            else if (t0 == t1)
                valid_param = t1;

            param_found = true;
        }
        else if (t1 > 0 && t0 < 0)
        {

            valid_param = t1;
            param_found = true;
        }
    }
    else if (discrim == 0)
    {

        valid_param = (-b) / (2 * a);
    }

    shared_ptr<Vec3> ret_ptr = NULL;

    if (param_found)
    {

        Vec3 ret_val = origin + valid_param * dest;

        ret_ptr = make_shared<Vec3>(ret_val.get_x(), ret_val.get_y(), ret_val.get_z());

    }

    return ret_ptr;
}

bool Sphere::get_reflective() {

    return this->reflective;

}

double Sphere::get_refractive_ind() {

    return this->refractive_ind;

}

Vec3 Sphere::calculate_normal(Vec3 poi) {

    Vec3 normal_vec = poi - this->center;

    return normal_vec;

}

Ray Sphere::calculate_normal_ray(Vec3 poi) {

    // first get center of sphere
    // then subtract center of sphere from poi --> this gives us vector from poi to center
    // then multiply by -1 to get our destination vector from poi --> dest will normalize automatically

    Vec3 poi_to_center = this->center - poi;
    Vec3 poi_to_world = -1*poi_to_center;

    Ray ret_val {poi, poi_to_world};

    return ret_val;

}