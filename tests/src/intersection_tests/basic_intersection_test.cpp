#include <iostream>
#include <fstream>
#include <memory>

#include "../../../lib/graphics_lib/vec3.h"
#include "../../../lib/geometry_lib/geometry.h"
#include "../../../lib/geometry_lib/sphere.h"
#include "../../../lib/graphics_lib/camera.h"


using std::cout;
using std::endl;
using std::shared_ptr;

int main() {

    int res_width = 1920;
    int res_height = 1080;

    // make geometry and light
    Vec3 sphere_coords {500, 200, 300};
    Sphere* first_sphere = new Sphere{sphere_coords, 75, 1, 100, 0x228B22, false}; 
    shared_ptr<Geometry> first (first_sphere);

    Light light {50, Vec3 {0, 0, 1090}, 0xfff49b};

    // make plane
    Plane plane {0, 0x808080};

    // collect scene geometry
    vector<shared_ptr<Geometry>> scene_geom;
    scene_geom.push_back(first);

    // assimilate scene
    shared_ptr<Scene> scene_ptr = std::make_shared<Scene>(0x87CEEB, scene_geom, light, plane);

    // initialize camera
    Camera cam {res_width, res_height, scene_ptr, "first_render.ppm"};

    // run render method
    cam.render();

}