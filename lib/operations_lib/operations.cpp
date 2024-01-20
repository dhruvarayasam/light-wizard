#include <iostream>
#include <math.h>
#include <vector>
#include "operations.h"
#include "../graphics_lib/ray.h"
#include "../graphics_lib/vec3.h"
#include "../graphics_lib/scene.h"


using std::vector;
using std::cout; 
using std::endl;

namespace Operations
{

    double round_to(double value, double precision = 0.001)
    {
        double res = std::round(value / precision);
        res = res * precision;
        return res;
    }



    /*
    This function will take a ray and will attempt to trace a path to the light
    source provided in the scene object. If it is blocked yet again, then that point will
    be in shadow and it will return a color code in hex format for the camera.render method
    to pass off and process into a pixel. 
    */

    int trace(const Ray& ray, const Vec3& poi, shared_ptr<Scene> scene_ptr) {

        const Light& prim_light = scene_ptr->get_primary_light();

        return 0;
    }

    bool output_to_file(std::ofstream& file, int color) {
        return true;
    }



    

}
