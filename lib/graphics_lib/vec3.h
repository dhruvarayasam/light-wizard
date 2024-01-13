#pragma once
#include <iostream>

/*

Vec3 class to handle vectors and vector operations. Essentially a wrapper for a location in 3D space (x, y, z).
Also contains many operator overloads for vector operations. Ray class extends Vec3 class as many operations are
similar.

*/


class Vec3 {
    
    double x;
    double y;
    double z;


    public:
        Vec3();
        Vec3(double a, double b, double c);

        // operator overloads
        friend std::ostream& operator<< (std::ostream& os, const Vec3& a);
        friend Vec3 operator+ (const Vec3& a, const Vec3& b);
        friend Vec3 operator- (const Vec3& a, const Vec3& b);
        friend double operator* (const Vec3& a, const Vec3& b); // dot product
        friend Vec3 operator* (const double& a, const Vec3& b); // vector times a constant




};