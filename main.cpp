#include <iostream>
#include <stdexcept>

#include "descriptor.h"
#include "featurepoint.h"
#include "baseiostream.h"
#include "fileiostream.h"
#include "euclidianmetric.h"
#include <string>
#include <fstream>

int main()
{
    try
    {
        FileIOStream in("input");
        std::vector<FeaturePoint> buf = in.getFeaturePoints();
        EuclidianMetric metric;
        std::cout << metric.getDistance(buf[0].descriptor(), buf[1].descriptor()) <<  std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    //std::ifstream file("input");

    return 0;
}

