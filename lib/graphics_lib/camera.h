
/*

This class handles functionality for the camera witnessing the scene. The camera will take in a Scene
object, which contains all validated geometry and planes, as well as resolution specifications for the output image.
It then shoots rays into the scene, testing for intersections (defined by the operations library) and setting the color of 
each pixel of the image.

*/

class Camera {

    int res_length;
    int res_width;

};