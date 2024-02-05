#include "light.h"


Light::Light(int lum, Vec3 pos, u_int32_t col) : luminosity(lum), position(pos), light_color(col) {}

// class methods

int Light::get_luminosity() {

    return this->luminosity; 

}

const Vec3& Light::get_position() const {

    const Vec3& position = this->position;

    return position;

}

u_int32_t Light::get_color() {

    return this->light_color;

}

