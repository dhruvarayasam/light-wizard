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

    shared_ptr<Vec3> closest_geom_intersection(Ray ray, shared_ptr<Scene> scene_ptr)
    {

        const vector<shared_ptr<Geometry>> &scene_geom = scene_ptr->get_geometry();

        shared_ptr<Vec3> ret_val = NULL;
        double distance = 100000000;

        // first check for intersection with geometry

        for (shared_ptr<Geometry> g : scene_geom) {

            shared_ptr<Vec3> poi = g->intersect(ray); // get intersection point
            
            // calculate minimum intersection
            if (poi != NULL) {

                double intersection_distance = calculate_distance(*poi, ray.get_orig());

                if (intersection_distance < distance) {

                    distance = intersection_distance;

                    ret_val = poi;

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

    Ray reflection_result_ray(Ray incident, shared_ptr<Geometry> intersected_geom) 
    {

    }

    u_int32_t compute_final_color_geometry (  ) 
    {



    }

    u_int32_t compute_final_color_plane(  ) {
        
    }

    bool solve_quadratic(const double &a, const double &b, const double &c, double &x0, double &x1) {
        float discr = b * b - 4 * a * c;
        if (discr < 0)
            return false;
        else if (discr == 0)
            x0 = x1 = -0.5 * b / a;
        else
        {
            float q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
            x0 = q / a;
            x1 = c / q;
        }
        if (x0 > x1)
            std::swap(x0, x1);

        return true;
    }



}
