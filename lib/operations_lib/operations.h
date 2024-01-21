#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../graphics_lib/vec3.h"
#include "../graphics_lib/ray.h"
#include "../graphics_lib/scene.h"

/*

This set of functions dictate the mathematical operations needed
to render the image. 

*/

using std::shared_ptr;


namespace Operations {

    // rounds the value to the specified precision 
    double round_to (double value);

    // This method returns true if a and b point in the same direction; i.e, if their components line up.
    bool verify_direct(const Ray& a, const Ray& b);


     /* 
    The trace function returns a color, represented in hex format.
    The trace function takes in a ray/scene object and traces a new ray from the
    point of intersection to the light source. Depending on whether it is blocked
    or other conditions, the trace function will return a color represented in hex format.

    Parameters: const Ray reference, const Vec3 reference and a const Scene reference.
    */
    int trace(const Ray& ray, const Vec3& poi, shared_ptr<Scene> scene_ptr);



    /*
    Given a file stream parameter and a color given in hex format, this function
    appends to the file the color values for that particular pixel. Returns true if
    file output was successful, or an error occured while trying to write.
    */
    bool output_to_file(std::ofstream& file, int color);
    
}