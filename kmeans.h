#ifndef KMEANS_H
#define KMEANS_H

#include <stdexcept>

#include "basealgorithm.h"
#include "basemetric.h"
#include "featurepoint.h"
#include "cluster.h"
#include "twoobject.h"


class KMeans: public BaseAlgorithm
{
private:
    BaseMetric *m_metric;

private:
    int descCmp(Descriptor &d1, Descriptor &d2);
    void clear(std::vector<int> masClus[], int k);
    void startInitialization(std::vector<Cluster> &, std::vector<FeaturePoint> &, int k);
    void attach(std::vector<int> masD[], int k, std::vector<Cluster> &vecC, std::vector<FeaturePoint> &vecFP);

public:
    KMeans(BaseMetric *ptrMetric = 0);

    std::vector<TwoObject<int, Cluster> > findCluster(std::vector<FeaturePoint> &vecPoints, int countCluster);
};

#endif // KMEANS_H
