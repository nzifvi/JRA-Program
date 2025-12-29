//
// Created by benja on 18.12.2025.
//

#ifndef VERTEX_H
#define VERTEX_H
#include <algorithm>


template <typename K, typename V> class MapItem {
private:
    K key;
    V value;


public:
    //CONSTRUCTORS AND DESTRUCTORS:
    MapItem(const K& key, const V& value): key(key), value(value) {};
    MapItem(K&& key, V&& value): key(std::move(key)), value(std::move(value)) {};

    // PUBLIC NON-ENCAPSULATION FUNCTION MEMBERS:

    // ENCAPSULATION FUNCTION MEMBERS:
    V getValue() const {return value;}
    void setValue(const V value) {this.value = value;}

    K getKey() const {return key;}
    void setKey(const K key) {key = key;}
};



#endif //VERTEX_H
