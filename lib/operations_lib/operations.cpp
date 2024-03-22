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

    shared_ptr<Vec3> closest_geom_intersection(Ray ray, shared_ptr<Scene> scene_ptr, shared_ptr<Geometry> intersected_geom)
    {

       return NULL;

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
