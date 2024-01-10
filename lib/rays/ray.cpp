#include <iostream>
#include "ray.h"

Ray :: Ray() {

    x = 0;
    y = 0;
    z = 0;

}

Ray :: Ray (float x, float y, float z) {

    x = x;
    y = y;
    z = z; 

}

Ray operator+ (Ray const& r1, Ray const& r2) {

    Ray r3 {r1.x+r2.x, r1.y+r2.y, r1.z+r2.z};

    return r3;
    
}
