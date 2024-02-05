#pragma once
#include "vec3.h"


class Light {

    int luminosity; // on a scale from 0-100, 100 being the brightest and 0 being no light at all
    Vec3 position {0, 0, 0}; // this will be changed in runtime to whatever height above the raster image
    u_int32_t light_color; // color of the light, encoded as an unsigned 32 bit integer.

    public:
        Light(int lum, Vec3 pos, u_int32_t col);

        // class methods
        int get_luminosity();
        const Vec3& get_position() const;
        u_int32_t get_color();

        


};