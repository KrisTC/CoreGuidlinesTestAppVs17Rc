#pragma once
#include <gsl/gsl>

class MyArray
{
public:
    //#pragma warning (push)
    //#pragma warning (disable : 26421)
    MyArray() : m_data(new int[4]) {
        gsl::span<int> d(m_data, 4);
        d[0] = 29;
        d[1] = 2;
        d[2] = 3;
        d[3] = 86;
    }
    //#pragma warning (pop)

    ~MyArray() {
        delete[] m_data;
    }

    operator gsl::span<int>() {
        gsl::span<int> d(m_data, 4);
        return d;
    }

private:
    //int* m_data;
    gsl::owner<int*> m_data;
};
