#pragma once
#include "light.h"
#include "../geometry_lib/geometry.h"
#include "plane.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Scene {

    u_int32_t background_color; // hex value representing an rgb value
    Plane plane;
    vector<shared_ptr<Geometry>> geometry;
    Light primary_light;



    bool validate_geometry(vector<Geometry> geo);

    public:

        Scene(int back_col, vector<shared_ptr<Geometry>> geo, Light prim_light, Plane p); // constructor
        int get_background_color();

        const vector<shared_ptr<Geometry>>& get_geometry();
        const Light& get_primary_light();
        const Plane get_plane();
        
};