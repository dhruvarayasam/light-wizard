#include <iostream>
#include "ray.h"

using std::endl;
using std::cout;

Ray :: Ray() {

    x = 0;
    y = 0;
    z = 0;

}

Ray :: Ray (float a, float b, float c) {

    x = a;
    y = b;
    z = c; 

}

Ray operator+ (Ray const& r1, Ray const& r2) {

    Ray r3 {r1.x+r2.x, r1.y+r2.y, r1.z+r2.z};

    return r3;
    
}

Ray operator- (Ray const& r1, Ray const& r2) {

    Ray r3 {r1.x-r2.x, r1.y-r2.y, r1.z-r2.z};

    return r3;


}

std::ostream& operator<<(std::ostream& os, Ray const& r1) {

    return os << r1.x << "," << r1.y << "," << r1.z << endl;

}



