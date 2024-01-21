#pragma once
#include <memory>
#include "../graphics_lib/ray.h"
#include "../graphics_lib/vec3.h"

using std::shared_ptr;


class Geometry {


    public:

        /*
        This is a base class meant for all the types of geometry in the scene.
        For now, we only have spheres, however as we add more shapes, they will all extend
        from this abstract class. All classes extending from Geometry must implement the intersect class, 
        which returns a shared pointer of an intersection point given a ray. If no such point exists,
        then this pointer will be null. 
        */
        virtual shared_ptr<Vec3> intersect(Ray ray) = 0;

};