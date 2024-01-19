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

    void round();

    public:
        Vec3();
        Vec3(double a, double b, double c);

        // functions 

        Vec3 normalize();
        double get_magnitude() const;


        // operator overloads
        friend std::ostream& operator<< (std::ostream& os, const Vec3& a);
        friend Vec3 operator+ (const Vec3& a, const Vec3& b);
        friend Vec3 operator- (const Vec3& a, const Vec3& b);
        friend double operator* (const Vec3& a, const Vec3& b); // dot product
        friend Vec3 operator* (const double& a, const Vec3& b); // vector times a constant
        friend bool operator== (const Vec3& a, const Vec3& b); // checking for equality between vectors (should this determined by whether thay have the same coordinates or the same magnittude/direciton)
        friend bool operator!= (const Vec3& a, const Vec3& b); // 
        friend bool operator< (const Vec3& a, const Vec3& b); // compares if magnititude of a is less than b
        friend bool operator> (const Vec3& a, const Vec3& b); // compares if magnitude of a is more than b
        friend bool operator<= (const Vec3& a, const Vec3& b); // compares if magnitidue of a is less than or equal to b
        friend bool operator>= (const Vec3& a, const Vec3& b); // compares if magnitude of a is more than or equal to b

};