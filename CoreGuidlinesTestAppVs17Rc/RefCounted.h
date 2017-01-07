#pragma once
#include <gsl/gsl>
#include <atomic>

// This is an massivly simplified version of our IUknown implemantation
class RefCounted
{
public:
    RefCounted();
    virtual ~RefCounted();
    void AddRef();
    void Release();
private:
    std::atomic<size_t> m_ref_count;
};

// This is a massive simplification of our smart pointer for creating and owning our 
// that follow our IUnknown implementation pattern.
class RefCountedDumbPtr {
public:
    RefCountedDumbPtr() : m_obj(new RefCounted) {}
    RefCountedDumbPtr(RefCounted* obj) : m_obj(obj) {
        m_obj->AddRef();
    }
    RefCountedDumbPtr(const RefCountedDumbPtr& other) : m_obj(other.m_obj) {
        m_obj->AddRef();
    }
    virtual ~RefCountedDumbPtr() {
        m_obj->Release();
    }
    RefCounted* Get() { return m_obj; }
private:
    gsl::owner<RefCounted*> m_obj;
};