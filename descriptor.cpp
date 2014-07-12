#include <stdexcept>

#include "descriptor.h"

Descriptor::Descriptor(int size): m_descriptor(size)
{
    m_size = size;
}

Descriptor::Descriptor(vec_t &vec, int size): m_descriptor(vec)
{
    m_size = size;
}

Descriptor::Descriptor(vec_t::iterator &st, vec_t::iterator &end): m_descriptor(st, end)
{
    m_size = m_descriptor.size();
}

int &Descriptor::operator[](const int index)
{
    if (index < 0 || index >= m_size)
        throw std::logic_error("Error: out_of_bounds!");

    return m_descriptor[index];
}

int Descriptor::size()
{
    return m_size;
}

int Descriptor::size() const
{
    return m_size;
}
