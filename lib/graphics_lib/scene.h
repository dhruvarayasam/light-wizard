#pragma once
#include "light.h"
#include "../geometry_lib/geometry.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Scene {

    int background_color; // hex value representing an rgb value
    int plane_position; // y value corresponding to where the plane will perpendicularly intersect the y axis at
    vector<shared_ptr<Geometry>> geometry;
    Light primary_light;



    bool validate_geometry(vector<Geometry> geo);

    public:

        Scene(int back_col, int plane_pos, vector<shared_ptr<Geometry>> geo, Light prim_light); // constructor

        const vector<shared_ptr<Geometry>>& get_geometry();
        const Light& get_primary_light();




};