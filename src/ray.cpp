#include <iostream>
#include "ray.h"


template<typename T> Ray<T> :: Ray() { // default constructor

    x = 0;
    y = 0;
    z = 0;

}

template<typename T> Ray<T> :: Ray(T a, T b, T c) {

    x= a;
    y= b;
    z= c;

}






