#ifndef BASEIOSTREAM_H
#define BASEIOSTREAM_H

#include <vector>

#include "featurepoint.h"

class BaseIOStream
{
protected:
   virtual FeaturePoint getNextFeaturePoint(const int size) = 0;
   virtual int getSizeDescriptor() = 0;
   virtual int getCountFeaturePoints() = 0;

public:
    BaseIOStream() { }
    virtual ~BaseIOStream() { }

    virtual std::vector<FeaturePoint> getFeaturePoints() = 0;
};

#endif // BASEIOSTREAM_H
