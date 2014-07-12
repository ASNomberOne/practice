#include "euclidianmetric.h"

double EuclidianMetric::getDistance(Descriptor &desc1, Descriptor &desc2)
{
    if (desc1.size() != desc2.size())
        throw std::logic_error("Error: out of bounds!");

    double distance = 0;
    for (int i = 0; i < desc1.size(); i++)
        distance += sqr(desc1[i] - desc2[i]);

    return std::sqrt(distance);
}

Descriptor EuclidianMetric::getCentroid(std::vector<FeaturePoint> &vecFeaturePoint)
{
    if (vecFeaturePoint.empty())
        throw std::runtime_error("Error: cluster is empty!");

    int sizeDesc = vecFeaturePoint[0].descriptor().size();
    Descriptor bufValue(sizeDesc);
    int countRec = vecFeaturePoint.size();

    for (int i = 0; i < sizeDesc; i++)
    {
        double result = 0;
        for (int j = 0; j < countRec; j++)
            result += vecFeaturePoint[j].descriptor()[i];
        bufValue[i] = result / countRec;
    }

    return bufValue;
}
