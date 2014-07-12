#ifndef FILEIOSTREAM_H
#define FILEIOSTREAM_H

#include <fstream>
#include <stdexcept>
#include <iostream>

#include "baseiostream.h"
#include "featurepoint.h"

class FileIOStream: public BaseIOStream
{
private:
    std::ifstream m_istream;

protected:
    int getSizeDescriptor();
    int getCountFeaturePoints();
    FeaturePoint getNextFeaturePoint(const int size);

public:
    FileIOStream(std::string file);
    ~FileIOStream();

    std::vector<FeaturePoint> getFeaturePoints();
};

#endif // FILEIOSTREAM_H
