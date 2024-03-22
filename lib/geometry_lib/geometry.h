#pragma once
#include <memory>
#include "../graphics_lib/ray.h"
#include "../graphics_lib/vec3.h"
#include "../graphics_lib/light.h"

using std::shared_ptr;

class Geometry
{

protected:
    bool reflective;
    int refractive_ind;
    u_int32_t color;

public:

    /*
    This is a base class meant for all the types of geometry in the scene.
    For now, we only have spheres, however as we add more shapes, they will all extend
    from this abstract class. All classes extending from Geometry must implement the intersect class,
    which returns a shared pointer of an intersection point given a ray. If no such point exists,
    then this pointer will be null.
    */
    virtual bool get_reflective() = 0;
    virtual double get_refractive_ind() = 0;
    virtual u_int32_t get_color() = 0;
    virtual shared_ptr<Vec3> calculate_poi(Ray incident_ray) = 0;
    virtual Vec3 calculate_normal(Vec3 poi) = 0;
    virtual Ray calculate_normal_ray(Ray incident_ray, Vec3 poi) = 0;
    virtual u_int32_t compute_reflected_color(Vec3 poi, Light light_src) = 0;
};