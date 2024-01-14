#pragma once

/*

Contains initialization information for a Sphere. Has radius,
refractive index, luminosity and opacity. Refractive index controls
how the sphere refracts light, luminosity controls how bright the object is (irrespective of color)
and opacity controls how transparent it is.

Luminosity and opacity are on a scale from 0 to 1.

*/

class Sphere
{
    double radius;
    double refractive_ind;
    double luminosity; //
    int opacity;       // on a scale of 1-100
    int color;         // represented in hexadecimal

public:
    Sphere(double rad, double ref, double lum, int op, int col);
};