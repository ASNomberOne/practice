#include <stdexcept>
#include <iostream>

#include "managercluster.h"

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

std::vector<Cluster> ManagerCluster::startAlgorithm(int countCluster)
{
    if (m_stream == 0 || m_algorithm == 0)
        throw std::runtime_error("Error: algorithm or iostream is nullptr!");

    std::vector<Cluster> vecCluster;

    try
    {
        std::vector<FeaturePoint> vecPoints = m_stream->getFeaturePoints();
        vecCluster = m_algorithm->findCluster(vecPoints, countCluster);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        throw;
    }

    return vecCluster;
}
