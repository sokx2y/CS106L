template <typename T>
Vector<T>::Vector() : elems(new T[4]), logicalSize(0), capacity(4) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] elems;
}

template <typename T>
size_t Vector<T>::size() const {
    return logicalSize;
}

template <typename T>
bool Vector<T>::empty() const {
    return logicalSize == 0;
}

template <typename T>
void Vector<T>::push_back(const T& elem) {
    if (logicalSize == capacity) {
        grow();
    }
    elems[logicalSize] = elem;
    logicalSize++;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return elems[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return elems[index];
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= logicalSize) {
        throw std::out_of_range("Vector::at out of range");
    }
    return elems[index];
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= logicalSize) {
        throw std::out_of_range("Vector::at out of range");
    }
    return elems[index];
}

template <typename T>
void Vector<T>::grow() {
    size_t newCapacity = capacity * 2;
    T* newElems = new T[newCapacity];

    for (size_t i = 0; i < logicalSize; i++) {
        newElems[i] = elems[i];
    }

    delete[] elems;
    elems = newElems;
    capacity = newCapacity;
}