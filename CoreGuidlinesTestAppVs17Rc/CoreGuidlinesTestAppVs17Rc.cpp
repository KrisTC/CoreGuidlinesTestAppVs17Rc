// CoreGuidlinesTestAppVs17Rc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <gsl/gsl>

int main()
{
    // Super simple bad code :)
    int* const p = new int[4]; 
    std::fill(p, p + 4, 0);     
    return *p; 
}

