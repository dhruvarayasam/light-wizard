#pragma once


/*

The Point class defines a point in 3D space. It has int x, y, z fields
that specify its location in the scene. Can be used to define the origin/destination
of a ray, center of a sphere, etc. Should mainly be used as reference points.

*/

class Point
{

public:
    float x;
    float y;
    float z;
    Point(float a, float b, float c);

    // operator overloads

    friend std::ostream& operator<< (std::ostream& os, const Point& point);

};