#pragma once
#include <gsl/gsl>
// An oversimplified version of our COM BSTR similar to CComBSTR
class MyBstr
{
public:
    MyBstr(BSTR bstr) : m_bstr(::SysAllocString(bstr)) { 
    }
    virtual ~MyBstr() {
        ::SysFreeString(m_bstr); 
    }

    operator gsl::cwstring_span<>() {
        return gsl::ensure_z(m_bstr);
    }

private:
    BSTR m_bstr;
};

