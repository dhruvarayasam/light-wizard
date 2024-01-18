#include <iostream>
#include <vector>
#include "scene.h"

using std::vector;

// constructors

// default --> adds 3 spheres into the geometry, each 25 units (pixels) apart
Scene::Scene() {
    vector<const Sphere&> geo;


}

Scene::Scene(vector<const Sphere&> geo) : geometry(geo) {} // special constructor for a preselected array of geometry



// class methods



// this method validates the geometry in the scene by making sure that no geometry interferes with each other
void validate_geometry () {

    // since geometry only contains spheres so far, we can assume that all geometry are spheres

}


