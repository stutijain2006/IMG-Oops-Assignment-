#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Vector {
    private :
    T* data;
    int size ;
    int current;
    void resize (){
        this->size *= 2;
        T* extend = new T[2*size];
        for (int i = 0; i < this->size/2; i++)
        {
            this->extend[i] = this->data[i];

        }
        delete [] this->data;
        this->data = extend;

    }
    public :
    Vector(){
        this->size = 1;
        this->current = 0;
        this->data = new T[this->size];
    }
    void push(const T& element ){
        if (this->current == this->size)
        {
            this->resize();
        }
        this->data[this->current] = element;
        this->current++;
    }    
    T get(int index) {
         if (index >= 0 && index < this->currentSize) {
            return this->data[index];
        }
        return T();
    }
    
    T size(){
        return this->current;
    
    };
    ~vector(){
        delete [] this->data;
    }

};