#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <vector>

const int DefaultSize = 128;

class Descriptor
{
private:
    typedef std::vector<int> vec_t;
    vec_t m_descriptor;
    int m_size;

public:
    Descriptor(int size = DefaultSize);
    Descriptor(vec_t &vec, int size = DefaultSize);
    Descriptor(vec_t::iterator &st, vec_t::iterator &end);

    int &operator[](const int index);
    int size();
    int size() const;
};

#endif // DESCRIPTOR_H
