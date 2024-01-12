#include <iostream>
#include "point.h"

Point::Point(float a, float b, float c) {

    x = a;
    y = b;
    z = c;

}

std::ostream& operator << (std::ostream& os, const Point& point) {

    os << "{" << point.x << "," << point.y << "," << point.z << "}";

    return os;

}

