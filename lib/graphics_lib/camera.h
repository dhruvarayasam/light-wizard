#pragma once
#include "scene.h"
#include "../operations_lib/operations.h"
#include <memory>
#include <fstream>

using std::shared_ptr;
using std::string;

/*
This class handles functionality for the camera witnessing the scene. The camera will take in a Scene
object, which contains all validated geometry and planes, as well as resolution specifications for the output image.
It then shoots rays into the scene, testing for intersections (defined by the operations library) and setting the color of
each pixel of the image.
*/

class Camera
{

    int res_length;
    int res_width;
    shared_ptr<Scene> scene;
    Vec3 pos{0.5, 1, 0.5};
    std::ofstream file; 

public:

    /*
    Takes a length/width parameter to specify the resolution of the raster image.
    It also takes a pointer to the scene object to ascertain what is actually being rendered.
    Additionally, it takes a string filename argument to open a stream to the output file that the camera
    will write to. This filestream will then be closed in the destructor. Throw an exception
    if opening the filestream is unsuccessful.
    */
    Camera(int length, int width, shared_ptr<Scene> s, string filename);

    /*
    This is where the magic happens. Rays are shot into the scene,
    and their colors are mixed and calculated here to set the color
    of the particular pixel that the original ray was shot from. It then outputs
    the color of the pixel to a seperate function, which writes that pixel
    to an actual PPM file.
    */
    void render();

    /*
    Traces a path to the light from a point of intersection given the scene, ray that intersected geometry,
    and the piece of intersected geometry. Calls on itself recursively if the object that is intersected
    is reflective/refractive, and eventually outputs a single hex code for a color that will be translated into
    a pixel in the final rendering.
    */
    u_int32_t trace(const Vec3 &poi, shared_ptr<Geometry> intersected_geom, const Ray &ray);

    /*
    Given a color, this method will use the reference to the output filestream attribute
    and output the color to the file. It will return true if the write was successful, false if not.
    If false, throw an exception and terminate execution.
    */
    bool output_to_file(u_int32_t color);
};