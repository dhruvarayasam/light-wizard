#include "vec3.h"

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(double a, double b, double c) : x(a), y(b), z(c) {}


std::ostream& operator << (std::ostream& os, const Vec3& a) {

    os << "{" << a.x << "," << a.y << "," << a.z << "}";

    return os;

}


Vec3 operator+ (const Vec3& a, const Vec3& b) {

    Vec3 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    return c;

}

Vec3 operator- (const Vec3& a, const Vec3& b) {

    Vec3 c;

    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;

}

double operator* (const Vec3& a, const Vec3& b) {

    double ret = 0;

    ret += a.x * b.x;
    ret += a.y * b.y;
    ret += a.z * b.z;

    return ret;

}

Vec3 operator* (const double& a, const Vec3& b) {

    Vec3 c;

    c.x = b.x * a;
    c.y = b.y * a;
    c.z = b.z * a;

    return c;


}





