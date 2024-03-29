#include <math.h>
#include "vec3.h"
#include "../operations_lib/operations.h"

// constructors

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(double a, double b, double c) : x(a), y(b), z(c) {}

double Vec3::get_x()
{

    return this->x;
}

double Vec3::get_y()
{

    return this->y;
}

double Vec3::get_z()
{

    return this->z;
}

void Vec3::set_x(double a)
{

    this->x = a;
}

void Vec3::set_y(double a)
{

    this->y = a;
}

void Vec3::set_z(double a)
{

    this->z = a;
}

std::ostream &operator<<(std::ostream &os, const Vec3 &a)
{

    os << "{" << a.x << "," << a.y << "," << a.z << "}";

    return os;
}

// operator overloads

Vec3 operator+(const Vec3 &a, const Vec3 &b)
{

    Vec3 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    c.round();

    return c;
}

Vec3 operator-(const Vec3 &a, const Vec3 &b)
{

    Vec3 c;

    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;

    c.round();

    return c;
}

double operator*(const Vec3 &a, const Vec3 &b)
{

    double ret = 0;

    ret += a.x * b.x;
    ret += a.y * b.y;
    ret += a.z * b.z;

    ret = Operations::round_to(ret);

    return ret;
}

Vec3 operator*(const double &a, const Vec3 &b)
{

    Vec3 c;

    c.x = b.x * a;
    c.y = b.y * a;
    c.z = b.z * a;

    c.round();

    return c;
}

bool operator==(const Vec3 &a, const Vec3 &b)
{

    bool x_bool = a.x == b.x;
    bool y_bool = a.y == b.y;
    bool z_bool = a.z == b.z;

    return x_bool && y_bool && z_bool;
}

bool operator!=(const Vec3 &a, const Vec3 &b)
{

    bool x_bool = a.x == b.x;
    bool y_bool = a.y == b.y;
    bool z_bool = a.z == b.z;

    return !x_bool || !y_bool || !z_bool;
}

bool operator<(const Vec3 &a, const Vec3 &b)
{

    return a.get_magnitude() < b.get_magnitude();
}

bool operator>(const Vec3 &a, const Vec3 &b)
{

    return a.get_magnitude() > b.get_magnitude();
}

bool operator<=(const Vec3 &a, const Vec3 &b)
{

    return a.get_magnitude() <= b.get_magnitude();
}

bool operator>=(const Vec3 &a, const Vec3 &b)
{

    return a.get_magnitude() >= b.get_magnitude();
}

// class methods

double Vec3::get_magnitude() const
{

    double res = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

    res = Operations::round_to(res);

    return res;
}

Vec3 Vec3::normalize()
{

    Vec3 a;

    double mag = this->get_magnitude();

    if (mag != 0)
    {
        a.x = Operations::round_to(this->x / mag);
        a.y = Operations::round_to(this->y / mag);
        a.z = Operations::round_to(this->z / mag);
    } else {

        a.x = 0;
        a.y = 0;
        a.z = 0;


    }

    return a;
}

void Vec3::round()
{

    this->x = Operations::round_to(this->x);
    this->y = Operations::round_to(this->y);
    this->z = Operations::round_to(this->z);
}
