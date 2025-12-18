//
// Created by benja on 18.12.2025.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <algorithm>
#include <iostream>

template <typename V>class DynamicArray {
private:
    V* ptrArray     = nullptr;
    int size        = 0;
    int capacity    = 0;

    // PRIVATE FUNCTION MEMBERS:
    void resize(const int newCapacity) {
        V* newArray = new V[newCapacity];
        const int loopBound = std::min(size, newCapacity);
        for (int i = 0; i < loopBound; i++) {
            newArray[i] = std::move(ptrArray[i]);
        }
        delete[] ptrArray;
        ptrArray = newArray;
        capacity = newCapacity;
    }

public:
    // CONSTRUCTORS AND DESTRUCTORS:
    DynamicArray(): ptrArray(new V[0]), size(0), capacity(0) {}

    DynamicArray(const int desiredCapacity): ptrArray(new V[desiredCapacity]), size(0), capacity(desiredCapacity) {}

    DynamicArray(const DynamicArray& other): ptrArray(new V[other.capacity]), size(other.size), capacity(other.capacity) {
        for (int i = 0; i < size; i++) {
            ptrArray[i] = other.ptrArray[i];
        }
    }

    DynamicArray(DynamicArray&& other): ptrArray(std::move(other.ptrArray)), size(other.size), capacity(other.capacity) {
        other.ptrArray = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    ~DynamicArray() {
        if (ptrArray != nullptr) {
            delete[] ptrArray;
        }
    }

    // PUBLIC NON-ENCAPSULATION FUNCTION MEMBERS:
    void insert(const int index, const V value) {
        if (ptrArray == nullptr) {
            throw -1;
        }else {
            if (size == capacity) {
                resize(std::max(1, 4*capacity));
            }
            for (int i = size; i > index; i--) {
                ptrArray[i] = std::move(ptrArray[i - 1]);
            }
            ptrArray[index] = value;
            size++;
        }
    }

    V remove(const int index) {
        if (ptrArray == nullptr) {
            throw -1;
        }else if (index >= size || index < 0) {
            throw -2;
        }else {
            V temp = std::move(ptrArray[index]);
            for (int i = index; i < size - 1; i++) {
                ptrArray[i] = std::move(ptrArray[i + 1]);
            }

            size--;
            if (size > 0 && size == capacity/4) {
                resize(capacity/4);
            }
            return temp;
        }
    }

    // ENCAPSULATION FUNCTION MEMBERS:
    V get(const int index) const {
        if (ptrArray == nullptr) {
            throw -1;
        }else if (index >= size) {
            throw -2;
        }else {
            return ptrArray[index];
        }
    }

    void set(const int index, const V value) {
        if (ptrArray == nullptr) {
            throw -1;
        }else if (index >= size) {
            throw -2;
        }else {
            ptrArray[index] = value;
        }
    }

    int getSize() const {return size;}

    int getCapacity() const {return capacity;}

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }else {
            DynamicArray temp(other);
            std::swap(this->ptrArray, temp.ptrArray);
            std::swap(this->size, temp.size);
            std::swap(this->capacity, temp.capacity);
            return *this;
        }
    }
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const DynamicArray<V>& array) {
    for (int i = 0; i < array.getSize(); i++) {
        os << array.get(i);
        if (i < array.getSize() - 1) {
            os << ", ";
        }
    }
    return os;
}


#endif //DYNAMICARRAY_H
