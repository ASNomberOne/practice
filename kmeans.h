#ifndef KMEANS_H
#define KMEANS_H

#include "basealgorithm.h"
#include "basemetric.h"

class KMeans: public BaseAlgorithm
{
private:
    BaseMetric *m_metric;
public:
    KMeans(BaseMetric *ptrMetric = 0): m_metric(ptrMetric) { }

    std::vector<Cluster> findCluster();
};

#endif // KMEANS_H
