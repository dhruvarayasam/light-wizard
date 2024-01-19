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
    double refractive_ind; // this has to be zero if opacity is at 100
    int opacity;       // on a scale of 1-100, where 100 is completely untransparent and 1 is most transparent
    int color;         // represented in hexadecimal
    int reflectivity; // on a measure of 0-100, where 0 is not reflective at all and 100 is most reflective
    

public:
    Sphere(double rad, double ref, int op, int col, int refle);

    double get_radius();
    double get_refractive_ind();
    int get_opacity();
    int get_color();
    int get_reflectivity();
};