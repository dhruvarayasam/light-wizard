#include "sphere.h"
#include <cmath>

using std::make_shared;
using std::shared_ptr;

Sphere::Sphere(Vec3 cent, double rad, double ref, int op, u_int32_t col, bool refle) : radius(rad), opacity(op), center(cent)
{

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

    If destination has z coordinate 0, then we know that it is the plane. Therefore, return NULL.

    */

    if (ray.get_dest().get_z() == 0) {

        return NULL;

    }

    Vec3 dest = ray.get_dest();
    Vec3 origin = ray.get_orig();
    int color = ray.get_color();

    // coefficients for equation

    Vec3 L = origin - this->center;

    double a = dest * dest;
    double b = 2 * dest * L;
    double c = (L * L) - this->radius;

    double t0, t1; // --> if intersection occurs, these variables will hold parameter values

    if (!Operations::solve_quadratic(a, b, c, t0, t1))
    {
        return NULL;
    }

    else
        return NULL;
}

bool Sphere::get_reflective()
{

    return this->reflective;
}

double Sphere::get_refractive_ind()
{

    return this->refractive_ind;
}

Vec3 Sphere::calculate_normal(Vec3 poi)
{

    Vec3 normal_vec = poi - this->center;

    return normal_vec;
}

Ray Sphere::calculate_normal_ray(Vec3 poi)
{

    // first get center of sphere
    // then subtract center of sphere from poi --> this gives us vector from poi to center
    // then multiply by -1 to get our destination vector from poi --> dest will normalize automatically

    Vec3 poi_to_center = this->center - poi;
    Vec3 poi_to_world = -1 * poi_to_center;

    Ray ret_val{poi, poi_to_world};

    return ret_val;
}

u_int32_t Sphere::compute_reflected_color(Vec3 poi, Light light_src)
{

    /*
    computes normal
    based on the angle between the normal and the light source, return the level of brightness that that point is
    experiencing
    */

    Vec3 to_light = poi - light_src.get_position();

    Vec3 normal = this->calculate_normal(poi);

    double hit_color = this->albedo / M_PI * light_src.get_luminosity() * light_src.get_color() * std::max(0.0, normal * (-1 * to_light));

    return hit_color;
}