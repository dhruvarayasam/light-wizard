#include <iostream>
#include "camera.h"

using std::cout;
using std::endl;
using std::shared_ptr;

Camera::Camera(int length, int width, shared_ptr<Scene> s) : res_length(length), res_width(width), scene(s) {

    cout << "Scene compilation initialized at resolution " << length << " x " << width << "." << endl;

}

void Camera::render() {

    /*
    KEEP IN MIND: WE HAVE TO SET LIGHTING RELATIVE TO RESOLUTION ALONG
    WITH OTHER SCALING OPERATIONS. 
    */


    /*

    CALCULATION FOR INTERSECTION

    We represent a ray in the format O + tD. t is a parameter and
    O and D are origin and destination. The format for representing a circle in 3D
    is x^2+y^2+z^2 = R^2. This can be denoted as P^2 - R^2 = 0, where P is a 3D vector.
    P can be substituted with O + tD. Simplifying, this gives us:

    D^2*t^2 + 2ODt + O^2 - R^2 = 0. To solve for our points of intersection,
    we solve for the discriminant. 
    
    If discriminant is >0, there are two intersections.
    If discriminant is =0, there is 1 intersection.
    If discriminant is <0, there are no intersections.

    This formula is easily modified for cases where spheres are not centered exactly
    at the origin.

    */

    cout << "camera render method called" << endl;


}


