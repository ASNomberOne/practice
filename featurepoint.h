#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H

#include <vector>

#include "descriptor.h"

class FeaturePoint
{
private:
    double m_x;
    double m_y;
    double m_fi;
    double m_s;
    int m_idImage;

    Descriptor m_descriptor;

public:
    FeaturePoint(int size = DefaultSize);
    FeaturePoint(double x, double y, double fi, double s, double id, int size = DefaultSize);

    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
    void setFi(double fi) { m_fi = fi; }
    void setS(double s) { m_s  = s; }
    void setIdImage(int id) { m_idImage = id; }

    double getX() { return m_x; }
    double getY() { return m_y; }
    double getFi() { return m_fi; }
    double getS() { return m_s; }
    int getIdImage() { return m_idImage; }

    Descriptor &descriptor() { return m_descriptor; }
};

#endif // FEATUREPOINT_H
