#pragma once
#include <gsl/gsl>

class MyArray
{
public:
    //#pragma warning (push)
    //#pragma warning (disable : 26421)
    MyArray() : m_data(new int[4]) {
        m_data[0] = 29;
        m_data[1] = 2;
        m_data[2] = 3;
        m_data[3] = 86;
    }
    //#pragma warning (pop)

    ~MyArray() {
        delete[] m_data;
    }

    operator gsl::span<int>() {
        return gsl::span<int>(m_data, 4);
    }

private:
    //int* m_data;
    gsl::owner<int*> m_data;
};
