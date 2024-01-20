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

        const Light& prim_light = scene_ptr->get_primary_light(); // get primary light source reference
        const vector<shared_ptr<Geometry>>& scene_geom = scene_ptr->get_geometry();

        Vec3 prim_light_pos = prim_light.get_position(); // get the position of the prim light source
        Vec3 vec_to_light = prim_light_pos - poi; // get vector that points in direction of the light
        Ray cast_ray {poi, prim_light_pos}; // ray that is casted from intersection point to light source

        /*
        
        As part of the tracing mechanism, we need to now extend this vector to the light source.
        If it intersects w/ any geometry, we need to determine if its a reflective/refractive object.
        If that is the case, calculate new vectors and recurse. Otherwise, we can determine that the pixel
        is in shadow. 
        
        */

       /*
       iterate through the geometry and see if our ray intersects with anything. out of the
       intersected geometry, determine which intersection is closest.
       */

      




        return 0;
    }

    bool output_to_file(std::ofstream& file, int color) {
        return true;
    }



    

}
