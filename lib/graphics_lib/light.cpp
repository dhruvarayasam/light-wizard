#include "light.h"


Light::Light(int lum) : luminosity(lum) {}

// class methods

int Light::get_luminosity() {

    return this->luminosity; 

}

const Vec3& Light::get_position() const {

    const Vec3& position = this->position;

    return position;

}

