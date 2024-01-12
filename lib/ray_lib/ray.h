
#include "../point_lib/point.h"
#include <iostream>

/*

The Ray class defines a ray; a line segment in 3D space that has both
origin and direction (in this case direction is represented by a Point dest
that is exactly 1 unit away from origin). The Ray class has a default constructor
that defines origin as {0, 0, 0} and destination as {1, 1, 1}. Also overloads the
output stream operator.

*/



class Ray {

    Point orig;
    Point dest;

    public:

        Ray();
        Ray(const Point& a, const Point& b);

        // operator overloads

        friend std::ostream& operator<< (std::ostream& os, const Ray& ray);


};