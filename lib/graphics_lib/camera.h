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
        using the scene class attribute, it shoots rays
        into the scene and calculates each pixel's color
        based on what the ray hits. from a high level, utilizes the intersection() 
        function in the Operations namespace to see if the ray hits anything.
        if so, calculates path ray must take to the light source and sees 
        if the pixel should be shaded or in light. 
        */
        bool trace();
};