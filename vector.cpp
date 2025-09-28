#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
    T* data;

    int capacity;
    
    int currentSize;

    void resize() {
        this->capacity *= 2;
        T* extend = new T[this->capacity];
        for (int i = 0; i < this->currentSize; i++) {
            extend[i] = this->data[i];
        }
        delete[] this->data;
        this->data = extend;
    }

public:
    Vector() {
        this->capacity = 1;
        this->currentSize = 0;
        this->data = new T[this->capacity];
    }

    void push(const T& element) {
        if (this->currentSize == this->capacity) {
            this->resize();
        }
        this->data[this->currentSize] = element;
        this->currentSize++;
    }

    T get(int index) const {
        if (index >= 0 && index < this->currentSize) {
            return this->data[index];
        }
        return T();
    }

    // This function is now unambiguous.
    int size() const {
        return this->currentSize;
    }

    ~Vector() {
        delete[] this->data;
    }
};

