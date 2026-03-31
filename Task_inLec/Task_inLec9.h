#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();

    size_t size() const;
    bool empty() const;

    void push_back(const T& elem);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& at(size_t index);
    const T& at(size_t index) const;

private:
    T* elems;
    size_t logicalSize;
    size_t capacity;

    void grow();
};

#include "Task_inLec9.cpp"