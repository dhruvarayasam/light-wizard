#include "sphere.h"
#include <cmath>

using std::make_shared;
using std::shared_ptr;

Sphere::Sphere(Vec3 cent, double rad, double ref, int op, u_int32_t col, bool refle) : radius(rad), opacity(op), center(cent)
{

    this->reflective = refle;
    this->refractive_ind = ref;
    this->color = col;
    this->opacity = op;
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

shared_ptr<Vec3> Sphere::calculate_poi(Ray incident_ray)
{
    // calculate discriminant of intersection equation

    // clean up this code

    shared_ptr<Vec3> ret_val;

    double b_sq = pow(2 * (incident_ray.get_orig() * incident_ray.get_dest()), 2);
    double ac = 4 * incident_ray.get_dest() * incident_ray.get_dest() * ((incident_ray.get_orig() * incident_ray.get_orig()) - pow(this->get_radius(), 2));

    double discriminant = b_sq - ac;

    if (discriminant < 0) NULL;

    else if (discriminant == 0) {

        ret_val = make_shared<Vec3>(incident_ray.get_orig() + ((-b_sq)/ 2 * (incident_ray.get_dest() * incident_ray.get_dest())) * incident_ray.get_dest());

    } else if (discriminant > 0) {

        double t0 = (2*(incident_ray.get_orig() * incident_ray.get_dest()) + discriminant) / 2 * (incident_ray.get_dest()*incident_ray.get_dest());
        double t1 = (2*(incident_ray.get_orig() * incident_ray.get_dest()) - discriminant) / 2 * (incident_ray.get_dest()*incident_ray.get_dest());

        Vec3 t0_vec = incident_ray.get_orig() + t0 * incident_ray.get_dest();
        Vec3 t1_vec = incident_ray.get_orig() + t1 * incident_ray.get_dest();

        if (t0 < 0) ret_val = make_shared<Vec3>(t1_vec);
        else if (t1 < 0) ret_val = make_shared<Vec3> (t0_vec);

        else { // both t0 and t1 are greater than zero; in such case, compute which one is closer to the origin of the ray

            if (Operations::calculate_distance(incident_ray.get_orig(), t0_vec) < Operations::calculate_distance(incident_ray.get_orig(), t0_vec)) {
                ret_val = make_shared<Vec3> (t0_vec);
            } else ret_val = make_shared<Vec3> (t1_vec);

        }
    }

    return ret_val;
}

bool Sphere::get_reflective()
{

    return this->reflective;
}

Vec3 Sphere::get_center() {

    return this->center;

}

double Sphere::get_refractive_ind()
{

    return this->refractive_ind;
}

Vec3 Sphere::calculate_normal(Vec3 poi)
{
    return (poi - this->center).normalize();
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

   /*
   
   compute refraction/reflect color
   
   */

    Vec3 to_light = poi - light_src.get_position();

    Vec3 normal = this->calculate_normal(poi);

    double hit_color = this->albedo / M_PI * light_src.get_luminosity() * light_src.get_color() * std::max(0.0, normal * (-1 * to_light));

    return hit_color;
}