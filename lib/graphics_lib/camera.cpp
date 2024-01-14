#include <iostream>
#include "camera.h"

using std::cout;
using std::endl;

Camera::Camera(int length, int width, Scene s) : res_length(length), res_width(width), scene(s) {

    cout << "Scene compilation initialized at resolution " << length << " x " << width << "." << endl;

}



