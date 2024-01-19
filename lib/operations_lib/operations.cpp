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



    int trace(const Ray& ray, const Vec3& poi, shared_ptr<Scene> scene_ptr) {

        

        
    }

    bool output_to_file(std::ofstream& file, int color) {

    }



    

}
