#ifndef BASEMETRIC_H
#define BASEMETRIC_H

#include <vector>

#include "descriptor.h"
#include "featurepoint.h"

class BaseMetric
{
public:
    BaseMetric() { }
    virtual ~BaseMetric() { }

    virtual double getDistance(Descriptor &desc1, Descriptor &desc2) = 0;
    virtual Descriptor getCentroid(std::vector<FeaturePoint> &descriptor, std::vector<int> &) = 0;
};

#endif // BASEMETRIC_H
