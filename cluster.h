#ifndef CLUSTER_H
#define CLUSTER_H

#include "descriptor.h"

class Cluster
{
private:
    Descriptor m_descriptor;
    int m_idCluster;

public:
    Cluster(int id = 0, int sizeDesc = DefaultSize): m_descriptor(sizeDesc), m_idCluster(id) { }

    void setId(int id) { m_idCluster = id; }
    int getId() { return m_idCluster; }

    Descriptor &descriptor() { return m_descriptor; }
};

#endif // CLUSTER_H
