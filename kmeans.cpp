#include "kmeans.h"

KMeans::KMeans(BaseMetric *ptrMetric): m_metric(ptrMetric)
{
}


void KMeans::attach(std::vector<int> masD[], int k,
                      std::vector<Cluster> &vecC,
                      std::vector<FeaturePoint> &vecFP)
{
    int countPoints = vecFP.size();
    for (int i = 0; i < countPoints; i++)
    {
        int index = 0;
        double minDistance = m_metric->getDistance(vecC[0].descriptor(), vecFP[i].descriptor());
        for (int j = 1; j < k; j++)
        {
            double bufDist = m_metric->getDistance(vecC[j].descriptor(), vecFP[i].descriptor());
            if (bufDist < minDistance)
            {
                index = j;
                minDistance = bufDist;
            }
        }
        masD[index].push_back(i);
    }
}

int KMeans::descCmp(Descriptor &d1, Descriptor &d2)
{
    bool flag = true;
    for (int i = 0; i < d1.size() && flag; i++)
        if (d1[i] != d2[i])
            flag = false;

    return flag ? 0 : 1;
}

void KMeans::clear(std::vector<int> masClus[], int k)
{
    for (int i = 0; i < k; i++)
        masClus[i].clear();
}

void KMeans::startInitialization(std::vector<Cluster> &vecClus,
                                        std::vector<FeaturePoint> &vecFP,
                                        int k)
{
    if (k <= 0 || (unsigned)k >= vecFP.size())
        throw std::logic_error("Error: out of bounds!");
    int step = vecFP.size() / k;

    for (int i = 0; i < k; i++)
    {
        vecClus[i].descriptor() = vecFP[i * step].descriptor();
        vecClus[i].setId(i);
    }
}

std::vector<TwoObject<int, Cluster> > KMeans::findCluster(std::vector<FeaturePoint> &vecPoints,
                                                int countCluster)
{
    std::vector<Cluster> vecCluster(countCluster);

    startInitialization(vecCluster, vecPoints, countCluster);
    std::vector<int> masVec[countCluster];

    bool flagChange;
    do
    {
        flagChange = false;
        clear(masVec, countCluster);
        attach(masVec, countCluster, vecCluster, vecPoints);
        for (int i = 0; i < countCluster; i++)
        {
            Descriptor newCentroid = m_metric->getCentroid(vecPoints, masVec[i]);
            if (descCmp(newCentroid, vecCluster[i].descriptor()))
                flagChange = true;
            vecCluster[i].descriptor() = newCentroid;
        }
    }
    while (flagChange);

    std::vector<TwoObject<int, Cluster> > vecResult;
    for (int i = 0; i < countCluster; i++)
        for (int j = 0; (unsigned int)j < masVec[i].size(); j++)
        {
            TwoObject<int, Cluster> bufValue(masVec[i][j], vecCluster[i]);
            vecResult.push_back(bufValue);
        }

    return vecResult;
}
