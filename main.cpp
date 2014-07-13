#include <iostream>
#include <stdexcept>

#include "descriptor.h"
#include "featurepoint.h"
#include "baseiostream.h"
#include "fileiostream.h"
#include "euclidianmetric.h"
#include "managercluster.h"
#include "kmeans.h"
#include "twoobject.h"

int main()
{
    try
    {
        FileIOStream in("input");
        EuclidianMetric metric;
        KMeans kmeans(&metric);
        ManagerCluster managerCluster(&kmeans, &in);
        std::vector<TwoObject<int, Cluster> > m_result = managerCluster.startAlgorithm(1);

        int size = m_result.size();
        for (int i = 0; i < size; i++)
            for (int j = 0; j < m_result[i].getObject2().descriptor().size(); j++)
                std::cout << m_result[i].getObject2().descriptor()[j] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
