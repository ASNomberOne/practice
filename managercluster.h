#ifndef MANAGERCLUSTER_H
#define MANAGERCLUSTER_H

#include "basealgorithm.h"
#include "baseiostream.h"
//#include "cluster.h"

class Cluster;

class ManagerCluster
{
    BaseAlgorithm *m_algorithm;
    BaseIOStream *m_stream;
    int m_countClusters;

public:
    ManagerCluster(BaseIOStream *ios = 0);
    ManagerCluster(BaseAlgorithm *algorithm, BaseIOStream *ios = 0);

    void setIOStream(BaseIOStream *ios);
    void setAlgorithm(BaseAlgorithm *alg);

    std::vector<Cluster> startAlgorithm(int countCluster);
};

#endif // MANAGERCLUSTER_H
