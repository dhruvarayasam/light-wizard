#include <iostream>
#include <vector>
#include "scene.h"
#include <memory>

using std::vector;
using std::endl;
using std::cout;

// constructors

Scene::Scene(int back_col, int plane_pos , vector<shared_ptr<Sphere>> geo, Light prim_light) : background_color(back_col), plane_position(plane_pos), geometry(geo), primary_light(prim_light){}



// class methods

// this method validates the geometry in the scene by making sure that no geometry interferes with each other
bool validate_geometry (vector<const Sphere&> geo) {

    // since geometry only contains spheres so far, we can assume that all geometry are spheres

    return true;

}

const vector<shared_ptr<Sphere>>& Scene::get_geometry() {

    const vector<shared_ptr<Sphere>>& ret_val = this->geometry;

    return ret_val;

}

const Light& Scene::get_primary_light() {


    const Light& ret_val = primary_light;

    return ret_val;

}


