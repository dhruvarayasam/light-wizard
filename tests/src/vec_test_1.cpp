#include <iostream>
#include "../../lib/graphics_lib/vec3.h"
#include <assert.h>

using std::cout;
using std::endl;

/*
Tests simple addition and 
*/



int main(void)
{
    Vec3 v1{1, 2, 3};
    Vec3 v2{2, 3, 4};

    Vec3 v3 = v1 + v2;

    Vec3 v4 {3, 5, 7};

    cout << v3 << endl;
    cout << v4 << endl;

    assert (v3 == v4);


}