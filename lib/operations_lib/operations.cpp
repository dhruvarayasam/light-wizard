#include <iostream>
#include "operations.h"
#include <math.h>

namespace Operations
{

    double round_to(double value, double precision = 0.001)
    {
        double res = std::round(value / precision) * precision;
        return res;
    }

    

}
