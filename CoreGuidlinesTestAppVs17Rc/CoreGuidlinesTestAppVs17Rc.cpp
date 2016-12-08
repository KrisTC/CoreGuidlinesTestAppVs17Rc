// CoreGuidlinesTestAppVs17Rc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <gsl/gsl>
#include <windows.h>
#include <atlbase.h>
#include <comutil.h>

#include "MyArray.h"
#include "RefCounted.h"
#include "MyString.h"
#include "MyBstr.h"

inline auto StringFunctionTest(const gsl::cwstring_span<>& s) {
    return s.length();
}

void StringFunctionTests() {
    StringFunctionTest(L"Hello GSL");
    StringFunctionTest(std::wstring(L"Hello GSL"));
    auto s = ::SysAllocString(L"Hello GSL");
    StringFunctionTest(gsl::ensure_z(s));

    CComBSTR bstr; 
    bstr.Attach(s);
    StringFunctionTest(gsl::ensure_z(bstr.operator LPWSTR())); // Can't just assign this :(

    _bstr_t bstrt {L"Hello GSL"};
    StringFunctionTest(gsl::ensure_z(bstrt.GetBSTR())); // Can't just assign this :(

    std::wstring wstr {L"Hello GSL"};
    StringFunctionTest(wstr);

    MyString mystr{ L"Hello GSL" };
    StringFunctionTest(wstr);

    MyBstr mybstr{ L"Hello GSL" };
    StringFunctionTest(mybstr);
}

void TestRefCounted() {
    gsl::owner<RefCounted*> a = new RefCounted();
    a->AddRef();
    a->Release();
    a->Release(); // Deletes itself, but the core checker doesn't know...how do I tell it?
} 

void TestRefCountedPtr() {
    RefCountedDumbPtr a;
    auto b = a;
    RefCountedDumbPtr c(a.Get());
}

int main()
{ 
    // Super simple bad code :)
    int* const p = new int[4]; 
    std::fill(p, p + 4, 0);
    
    // Create my odd array class
    MyArray a;
    
    // Test strings
    StringFunctionTests();

    // Test ref counted (COM like) classes
    TestRefCounted();
    TestRefCountedPtr();

    return 0;
}

