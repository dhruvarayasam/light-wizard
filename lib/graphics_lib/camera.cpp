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

    cout << "camera render method called" << endl;


}


