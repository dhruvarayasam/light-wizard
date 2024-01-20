#include "vec3.h"


class Light {

    int luminosity; // on a scale from 0-100, 100 being the brightest and 0 being no light at all
    Vec3 position {0, 0, 0}; // this will be changed in runtime to whatever height above the raster image

    public:
        Light(int lum);

        


};