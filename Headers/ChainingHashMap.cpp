//
// Created by benja on 18.12.2025.
//

#include "ChainingHashMap.h"
#include "Graph.h"
#include <type_traits>
#include <stdexcept>
/*
template<typename K, typename V>
ChainingHashMap<K,V>::ChainingHashMap(): mapSize(1), itemCount(0), loadFactor(0), ptrMap(new DynamicArray<MapItem<K, V>>[mapSize]){}

template<typename K, typename V>
ChainingHashMap<K, V>::~ChainingHashMap() {
    if (ptrMap != nullptr) {
        delete[] ptrMap;
    }
}

template<typename K, typename V>
int ChainingHashMap<K, V>::hash(K key) {
    if constexpr (std::is_same_v<K, ComputationalGraphVertex>) {
        std::string vertexID = key.vertexID;
        unsigned long h = 5381;
        for (const char c : vertexID) {
            h = ((h << 5) + h) + c;
        }
        return static_cast<int>(h % mapSize);
    }else {

    }
}

template<typename K, typename V>
void ChainingHashMap<K, V>::resize(const int newMapSize) {
    DynamicArray<MapItem<K, V>>* ptrNewMap = new DynamicArray<MapItem<K, V>>[newMapSize];
    const int oldMapSize = mapSize;
    mapSize = newMapSize;

    for (int i = 0; i < oldMapSize; i++) {
        for (int j = 0; j < ptrMap[i].getSize(); j++) {
            MapItem<K, V>& item = ptrMap[i].get(j);
            const int newHashedIndex = hash(item.getKey());
            ptrNewMap[newHashedIndex].insert(
                ptrNewMap[newHashedIndex].getSize(),
                std::move(item)
                );
        }
    }
    delete[] ptrMap;
    ptrMap = ptrNewMap;
    loadFactor = static_cast<float>(itemCount) / static_cast<float>(mapSize);
}

template<typename K, typename V>
DynamicArray<MapItem<K, V> > ChainingHashMap<K, V>::getChainCopy(const int hashedIndex) {
    return ptrMap[hashedIndex];
}

template<typename K, typename V>
DynamicArray<MapItem<K, V> > &ChainingHashMap<K, V>::getChainRef(const int hashedIndex) {
    return ptrMap[hashedIndex];
}


template<typename K, typename V>
void ChainingHashMap<K, V>::insert(K key, V value) {
    if (loadFactor > maxLoadFactor) {
        resize(mapSize * 2);
    }

    int hashedIndex = hash(key);
    DynamicArray<MapItem<K, V>>& chain = getChainRef(hashedIndex);
    for (int i = 0; i < chain.getSize(); i++) {
        if (chain.get(i).getKey() == key) {
            chain.get(i).setValue(value);
            return;
        }
    }
    ptrMap[hashedIndex].insert(
        ptrMap[hashedIndex].getSize(),
        MapItem<K, V>(key, value));
    itemCount++;
    loadFactor = static_cast<float>(itemCount) / static_cast<float>(mapSize);
}

template<typename K, typename V>
MapItem<K, V> ChainingHashMap<K, V>::get(K key) {
    const int hashedIndex = hash(key);
    if (hashedIndex >= mapSize) {
        throw std::out_of_range("Hash of given key is larger than size of ChainingHashMap");
    }else {
        DynamicArray<MapItem<K, V>>& chain = getChainRef(hashedIndex);
        for (int i = 0; i < chain.getSize(); i++) {
            if (chain.get(i).getKey() == key) {
                return chain.getItem(i);
            }
        }
        throw std::out_of_range("Item with given key does not exist in ChainingHashMap");
    }
}
*/