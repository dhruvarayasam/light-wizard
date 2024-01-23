#include <math.h>
#include "operations.h"
#include "Config.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;

namespace Operations
{

    double round_to(double value)
    {
        double res = std::round(value / PRECISION_CONSTANT);
        res = res * PRECISION_CONSTANT;
        return res;
    }

    shared_ptr<Vec3> closest_intersection(Ray& ray, shared_ptr<Scene> scene_ptr, shared_ptr<Geometry> intersected_geom)
    {

        const vector<shared_ptr<Geometry>> &scene_geom = scene_ptr->get_geometry();

        shared_ptr<Vec3> ret_val;
        double distance = MAXFLOAT;

        for (shared_ptr<Geometry> g : scene_geom) {

            shared_ptr<Vec3> poi = g->intersect(ray); // get intersection point
            
            // calculate minimum intersection
            if (poi != NULL) {

                double intersection_distance = calculate_distance(*poi, ray.get_orig());

                if (distance < intersection_distance) {

                    distance = intersection_distance;

                    ret_val = poi;

                    intersected_geom = g;

                }

            }
            
        }

        return ret_val;


    }

    double calculate_distance(Vec3 vec0, Vec3 vec1) {

        double x = vec1.get_x() - vec0.get_x();
        double y = vec1.get_y() - vec0.get_y();
        double z = vec1.get_z() - vec0.get_z();

        double result = sqrt((x*x) + (y*y) + (z*z));

        result = round_to(result);

        return result;

    }



    Ray refraction_result_ray(Ray incident, shared_ptr<Geometry> intersected_geom) {

        

    }

    Ray reflection_result_ray(Ray incident, shared_ptr<Geometry> intersected_geom) {

    }

    u_int32_t compute_intensity(u_int32_t default_light_intensity, Vec3 poi, Light light_src, shared_ptr<Geometry> intersected_geom) {

        /*
        computes normal
        based on the angle between the normal and the light source, return the level of brightness that that point is
        experiencing
        */

       double dot = poi * light_src.get_position();
       double mag_product = poi.get_magnitude() * light_src.get_position().get_magnitude();

       double angle = acos(dot / mag_product);

       

    }

}
