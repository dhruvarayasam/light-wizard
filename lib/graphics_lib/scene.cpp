#include <iostream>
#include "scene.h"

using std::vector;
using std::endl;
using std::cout;

// constructors

Scene::Scene(int back_col, vector<shared_ptr<Geometry>> geo, Light prim_light, Plane p) : background_color(back_col), geometry(geo), primary_light(prim_light), plane(p) {}



// class methods

int Scene::get_background_color() {

    return this->background_color;

}

// this method validates the geometry in the scene by making sure that no geometry interferes with each other
bool validate_geometry (vector<Geometry> geo) {

    // since geometry only contains spheres so far, we can assume that all geometry are spheres

    return true;

}

const vector<shared_ptr<Geometry>>& Scene::get_geometry() {

    const vector<shared_ptr<Geometry>>& ret_val = this->geometry;

    return ret_val;

}

const Light& Scene::get_primary_light() {


    const Light& ret_val = this->primary_light;

    return ret_val;

}

const Plane Scene::get_plane() {

    return this->plane;

}


