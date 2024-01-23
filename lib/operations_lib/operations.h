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


    // This method calculates the distance between two points.
    double calculate_distance(Vec3 vec1, Vec3 vec2);

    shared_ptr<Vec3> closest_intersection(Ray& ray, shared_ptr<Scene> scene_ptr, shared_ptr<Geometry> intersected_geom);


    /*
    This function calculates and returns the refracted ray that exits the piece of intersected geometry.
    */
    Ray refraction_result_ray(Ray incident, shared_ptr<Geometry> intersected_geom);

    /*
    This function calculates and returns the reflected ray that exits the piece of intersected geometry.
    */
    Ray reflection_result_ray(Ray incident, shared_ptr<Geometry> intersected_geom);

    /*
    This method computes the intensity of light that should be shed on a particular point
    given the default intensity of the light source and the point of intersection, i.e the point
    we are trying to shade.
    */
    u_int32_t compute_intensity(u_int32_t default_light_intensity, Vec3 poi);
    
}