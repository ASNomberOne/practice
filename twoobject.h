#ifndef TWOOBJECT_H
#define TWOOBJECT_H

#include "cluster.h"

template <typename T1 = int, typename T2 = Cluster>
class TwoObject
{
private:
    T1 m_obj1;
    T2 m_obj2;

public:
    TwoObject(T1 obj1, T2 obj2): m_obj1(obj1), m_obj2(obj2) { }

    void setObject1(T1 obj) { m_obj1 = obj; }
    void setObject2(T2 obj) { m_obj2 = obj; }

    T1 getObject1() { return m_obj1; }
    T2 getObject2() { return m_obj2; }
};

#endif // TWOOBJECT_H
