//
// Created by benja on 18.12.2025.
//

#ifndef CHAININGHASHMAP_H
#define CHAININGHASHMAP_H

#include "MapItem.h"
#include "DynamicArray.h"
/*
template <typename K, typename V> class ChainingHashMap {
private:
    DynamicArray<MapItem<K,V>>* ptrMap;
    int mapSize;
    int itemCount;
    int loadFactor;
    float maxLoadFactor = 0.75;

    int hash(K key);
    void resize(const int newMapSize);
    DynamicArray<MapItem<K, V>>& getChainRef(const int hashedIndex);

public:
    ChainingHashMap();
    ~ChainingHashMap();

    void insert(K key, V value);
    MapItem<K,V> get(K key);
    DynamicArray<MapItem<K,V>> getChainCopy(const int hashedIndex);
};


*/
#endif //CHAININGHASHMAP_H
