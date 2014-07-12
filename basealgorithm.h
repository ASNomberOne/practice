#ifndef BASEALGORITHM_H
#define BASEALGORITHM_H

#include <vector>

#include "featurepoint.h"
#include "cluster.h"


class BaseAlgorithm
{
public:
    BaseAlgorithm() { }
    virtual ~BaseAlgorithm() { }

    virtual std::vector<Cluster> findCluster(std::vector<FeaturePoint> &vecFP, int countCluster) = 0;
};

#endif // BASEALGORITHM_H
