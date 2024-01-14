#pragma once
#include "../geometry_lib/sphere.h"
#include <memory>

using std::unique_ptr;

class Scene {

    unique_ptr<Sphere> geometry; // pointer to dynamically allocated array of geometry in the scene

    void validate_geometry();

    public:
        Scene(unique_ptr<Sphere> geo); // constructor

};