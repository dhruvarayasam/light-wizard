#include <iostream>
#include <vector>
#include "scene.h"
#include <memory>

using std::vector;
using std::endl;
using std::cout;

// constructors

Scene::Scene() {

    vector<shared_ptr<Sphere>> geom {};

    this->background_color = 0x87CEEB;
    this->plane_position = 0;
    this->geometry = geom; 


}

Scene::Scene(int back_col, int plane_pos , vector<shared_ptr<Sphere>> geo, Light prim_light) : background_color(back_col), plane_position(plane_pos), geometry(geo), primary_light(prim_light){}



// class methods

// this method validates the geometry in the scene by making sure that no geometry interferes with each other
bool validate_geometry (vector<const Sphere&> geo) {

    // since geometry only contains spheres so far, we can assume that all geometry are spheres

    return true;

}


