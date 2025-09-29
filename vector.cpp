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

    Vector(const Vector& other) {
        this->capacity = other.capacity;
        this->currentSize = other.currentSize;
        this->data = new T[this->capacity];
        for (int i = 0; i < this->currentSize; i++) {
            this->data[i] = other.data[i];
        }
    }

    Vector& operator= (const Vector& other){
        if (this == &other) return *this;
        delete[] this-> data;

        this->capacity=other.capacity;
        this->currentSize= other.currentSize;
        this->data = new T[this->capacity];
        for (int i=0; i< this->currentSize; i++){
            this->data[i]= other.data[i];
        };
        return *this;
    }

    void push(const T& element) {
        if (this->currentSize == this->capacity) {
            this->resize();
        }
        this->data[this->currentSize] = element;
        this->currentSize++;
    }

    void remove(int index){
        if (index<0 || index >= this->currentSize) {
            return;
        }
        for (int i = index; i < this->currentSize - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->currentSize--;
    }

    int find(const T& element) const {
        for (int i = 0; i < this->currentSize; i++) {
            if (this->data[i] == element) {
                return i;
            }
        }
        return -1;
    }

    T get(int index) const {
        if (index >= 0 && index < this->currentSize) {
            return this->data[index];
        }
        return T();
    }

    T& operator[](int index) {
        return this->data[index];
    }

    const T& operator[](int index) const {
        return this->data[index];
    }

    // This function is now unambiguous.
    int size() const {
        return this->currentSize;
    }

    bool isEmpty() const {
        return this->currentSize == 0;
    }

    void clear(){
        this->currentSize =0;
    }

    ~Vector() {
        delete[] this->data;
    }
};

