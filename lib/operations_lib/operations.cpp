#include <iostream>
#include "operations.h"
#include <math.h>

namespace Operations
{

    double round_to(double value, double precision = 1.0)
    {

        return std::round(value / precision) * precision;
    }

}
