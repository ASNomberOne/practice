#include "featurepoint.h"

FeaturePoint::FeaturePoint(int size): m_descriptor(size) { }

FeaturePoint::FeaturePoint(double x, double y, double fi, double s, double id, int size): m_descriptor(size)
{
    m_x = x;
    m_y = y;
    m_fi = fi;
    m_s = s;
    m_idImage = id;
}
