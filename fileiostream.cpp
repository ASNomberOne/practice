#include "fileiostream.h"

FileIOStream::FileIOStream(std::string file): m_istream(file.c_str())
{
    if (!m_istream.is_open())
        throw std::runtime_error("Error: cannot open file!");
}

FileIOStream::~FileIOStream()
{
    if (m_istream.is_open())
        m_istream.close();
}

int FileIOStream::getSizeDescriptor()
{
    int size = 0;
    if (!(m_istream >> size))
        throw std::runtime_error("Error: invalid reading!");
    return size;
}

int FileIOStream::getCountFeaturePoints()
{
    int count = 0;
    if (!(m_istream >> count))
        throw std::runtime_error("Error: invalid reading!");
    return count;
}

FeaturePoint FileIOStream::getNextFeaturePoint(const int size)
{
    FeaturePoint tmp(size);
    double bufValue = 0;
    int bufId = 0;

    if (m_istream >> bufValue) tmp.setX(bufValue);
    else throw std::runtime_error("Error: cannot read x value.");

    if (m_istream >> bufValue) tmp.setY(bufValue);
    else throw std::runtime_error("Error: cannot read y value.");

    if (m_istream >> bufValue) tmp.setFi(bufValue);
    else throw std::runtime_error("Error: cannot read fi value.");

    if (m_istream >> bufValue) tmp.setS(bufValue);
    else throw std::runtime_error("Error: cannot read s value.");

    if (m_istream >> bufId) tmp.setIdImage(bufId);
    else throw std::runtime_error("Error: cannot read idImage value.");

    bool flag = true;
    for (int i = 0; i < size && flag; i++)
        if (!(m_istream >> tmp.descriptor()[i]))
            flag = false;
    if (!flag) throw std::runtime_error("Error: cannot read descriptor!");

    return tmp;
}

std::vector<FeaturePoint> FileIOStream::getFeaturePoints()
{
    std::vector<FeaturePoint> buffer;
    int sizeDescriptor = 0;
    int countRecord = 0;

    sizeDescriptor = getSizeDescriptor();
    countRecord = getCountFeaturePoints();
    for (int i = 0; i < countRecord; i++)
        buffer.push_back(getNextFeaturePoint(sizeDescriptor));

    return buffer;
}
