#include <stdexcept>
#include <iostream>

#include "managercluster.h"
#include "cluster.h"
#include "twoobject.h"

ManagerCluster::ManagerCluster(BaseAlgorithm *algorithm, BaseIOStream *ios)
{
    m_algorithm = algorithm;
    m_stream = ios;
}

ManagerCluster::ManagerCluster(BaseIOStream *ios)
{
    m_stream = ios;
}

void ManagerCluster::setAlgorithm(BaseAlgorithm *alg)
{
    m_algorithm = alg;
}

void ManagerCluster::setIOStream(BaseIOStream *ios)
{
    m_stream = ios;
}

std::vector<TwoObject<int, Cluster> > ManagerCluster::startAlgorithm(int countCluster)
{
    if (m_stream == 0 || m_algorithm == 0)
        throw std::runtime_error("Error: algorithm or iostream is nullptr!");
    if (countCluster < 1)
        throw std::domain_error("Error: domain error!");

    std::vector<TwoObject<int, Cluster> > vecResult;

    //try
    //{
        std::vector<FeaturePoint> vecPoints = m_stream->getFeaturePoints();
        vecResult = m_algorithm->findCluster(vecPoints, countCluster);
    //}
    /*catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw;
    }*/

    return vecResult;
}
