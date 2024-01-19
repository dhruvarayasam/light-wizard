#pragma once
#include "scene.h"
/*

This class handles functionality for the camera witnessing the scene. The camera will take in a Scene
object, which contains all validated geometry and planes, as well as resolution specifications for the output image.
It then shoots rays into the scene, testing for intersections (defined by the operations library) and setting the color of 
each pixel of the image.

*/

class Camera {

    int res_length;
    int res_width;
    Scene scene;

    public:
        Camera(int length, int width, Scene s);

        /*
        This is where the magic happens. Rays are shot into the scene,
        and their colors are mixed and calculated here to set the color
        of the particular pixel that the original ray was shot from. It then outputs
        the color of the pixel to a seperate function, which writes that pixel
        to an actual PPM file. 
        */
        void render();


};