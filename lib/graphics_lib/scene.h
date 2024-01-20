#pragma once
#include "../geometry_lib/sphere.h"
#include "light.h"
#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Scene {

    int background_color; // hex value representing an rgb value
    int plane_position; // y value corresponding to where the plane will perpendicularly intersect the y axis at
    vector<shared_ptr<Sphere>> geometry;
    Light primary_light;



    bool validate_geometry(vector<Sphere> geo);

    public:

        Scene(int back_col, int plane_pos, vector<shared_ptr<Sphere>> geo, Light prim_light); // constructor

        const vector<shared_ptr<Sphere>>& get_geometry();
        const Light& get_primary_light();




};