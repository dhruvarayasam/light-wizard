#pragma once
#include "../geometry_lib/sphere.h"
#include <iostream>
#include <vector>

using std::vector;


class Scene {

    vector<const Sphere&> geometry; 
    void validate_geometry();

    public:
        Scene();
        Scene(vector<const Sphere&> geo); // constructor

};