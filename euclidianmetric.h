#ifndef EUCLIDIANMETRIC_H
#define EUCLIDIANMETRIC_H

#include <cmath>
#include <stdexcept>
#include <vector>

#include "basemetric.h"
#include "descriptor.h"
#include "featurepoint.h"

inline double sqr(double x) { return x * x; }

class EuclidianMetric: public BaseMetric
{
public:
    EuclidianMetric() { }
    ~EuclidianMetric() { }

    double getDistance(Descriptor &desc1, Descriptor &desc2);
    Descriptor getCentroid(std::vector<FeaturePoint> &vecFeaturePoint);
};

#endif // EUCLIDIANMETRIC_H
