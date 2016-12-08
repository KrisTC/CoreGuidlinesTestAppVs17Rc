#include "stdafx.h"
#include "RefCounted.h"

RefCounted::RefCounted() : m_ref_count(1)
{
}

RefCounted::~RefCounted()
{
}

void RefCounted::AddRef()
{
    m_ref_count++;
}

void RefCounted::Release()
{
    if (--m_ref_count == 0) {
        delete this;
    }
}
