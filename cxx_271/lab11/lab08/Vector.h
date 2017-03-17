#include <iostream>
using namespace std;

template <typename TYPE>
class Vector
{
private:
    TYPE * m_ptr;
    int m_space;
    int m_last;

public:
    Vector()
    {
        m_ptr = new TYPE[10];
        m_space = 10;
        m_last =0;
    }
    ~Vector()
    {
        delete[] m_ptr;
    }
    void add(TYPE value)
    {
        if (m_last >= m_space)
        {
            TYPE * temp = new TYPE[m_space *2];
            for (int i=0; i < m_last; i++)
                temp[i] = m_ptr[i];
            delete[] m_ptr;
            m_ptr = temp;
            m_space = 2*m_space;
            cout << "Doubling space" << endl;
        }
        m_ptr[m_last++] = value;
    }
    int size()
    {
        return m_last;
    }
    TYPE & operator[] (int index)
    {
        return m_ptr[index];
    }
};
