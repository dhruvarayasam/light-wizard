#include <iostream>
#include "ray.h"


template<typename T> 
Ray<T> :: Ray() { // default constructor

    x = 0;
    y = 0;
    z = 0;

}

template<typename T> 
Ray<T> :: Ray(T a, T b, T c) {

    x= a;
    y= b;
    z= c;

}


template <typename T>
Ray<T>* operator+ (Ray<T> const& r1, Ray<T> const& r2) {

    Ray<T>* ret_val;

    ret_val->x = r1->x + r2->x;
    ret_val->y = r1->y + r2->y; 
    ret_val->z = r1->z + r2->z;

    return ret_val;

}

template <typename T>
Ray<T>* operator- (Ray<T> const& r1, Ray<T> const& r2) {
    Ray<T>* ret_val;

    ret_val->x = r1->x - r2->x;
    ret_val->y = r1->y - r2->y;
    ret_val->z = r1->z - r2->z;

}

template <typename T>
T* operator* (Ray<T> const& r1, Ray<T> const& r2) {

    T& val = 0;

    val += r1->x * r2->x;
    val += r1->y * r2->y;
    val += r1->z * r2->z;

    return val;

}

