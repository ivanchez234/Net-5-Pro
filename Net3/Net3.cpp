#include <iostream>
#include <stdexcept> 

template <typename T>
class MyVector {
private:
    T* data;         
    size_t v_size;     
    size_t v_capacity;

   
    void add_memory() {
        v_capacity = (v_capacity == 0) ? 1 : v_capacity * 2;

        T* new_data = new T[v_capacity];

        for (size_t i = 0; i < v_size; ++i) {
            new_data[i] = data[i];    
        }

        delete[] data;                
        data = new_data;             
    }
    MyVector(const MyVector& other) {
        v_size = other.v_size;
        v_capacity = other.v_capacity;

        if (v_capacity > 0) {
            data = new T[v_capacity];
            for (size_t i = 0; i < v_size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }
    MyVector& operator=(const MyVector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        
        v_size = other.v_size;
        v_capacity = other.v_capacity;

        if (v_capacity > 0) {
            data = new T[v_capacity];
            for (size_t i = 0; i < v_size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }

        return *this;
    }
public:
    MyVector() : data(nullptr), v_size(0), v_capacity(0) {}

    ~MyVector() {
        delete[] data;
    }

    size_t size() const { return v_size; }
    size_t capacity() const { return v_capacity; }

    void push_back(T value) {
        if (v_size >= v_capacity) {
            add_memory();
        }
        data[v_size++] = value;
    }

    T& at(int index) {
        if (index < 0 || index >= v_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};