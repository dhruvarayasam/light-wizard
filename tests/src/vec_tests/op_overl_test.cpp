#include <iostream>
#include "../../lib/graphics_lib/vec3.h"
#include <assert.h>

using std::cout;
using std::endl;

/*
Tests simple addition and equality operators.
*/



int main(void)
{

    // addition tests
    Vec3 v1{1, 2, 3};
    Vec3 v2{2, 3, 4};

    Vec3 v3 = v1 + v2;

    Vec3 v4 {3, 5, 7};

    cout << v3 << endl;
    cout << v4 << endl;

    assert (v3 == v4); // testing that the sum of v1 and v2 is equal to v4


    // subtraction test
    Vec3 v5 {1, 2, 3};
    Vec3 v6 {4, 5, 6};

    Vec3 v7 = v5 - v6;
    cout << v7 << endl;

    assert(v7 == (Vec3 {-3, -3, -3}));


    // dot product tests
    Vec3 dot1 {1, 2, 3};
    Vec3 dot2 {4, 5, 6};

    double res = dot1 * dot2;

    Vec3 dot3 {5, 9, 8};
    Vec3 dot4 {14, 2, 1};

    double res2 = dot3 * dot4;

    assert(res == 32);
    assert(res2 == 96);

    // comparison operators
    // Vec3 comp1 {1,2,3};
    // Vec3 comp2 {4, 5, 6};

    // assert(!(comp1 == comp2)); // not equals

    // Vec3 comp3 {1, 2, 3};

    // assert(comp1 == comp3); // equals

    Vec3 comp4 {1, 1, 1}; // greater than/less than
    Vec3 comp5 {2, 2, 2};
    Vec3 comp6 {3,3,3};
    Vec3 comp7 {1, 1, 1};

    assert(comp4 < comp5);
    assert(comp6 > comp5);

    assert (comp4 <= comp7);
    assert (comp6 >= comp7);
    

    





    return 0;

}