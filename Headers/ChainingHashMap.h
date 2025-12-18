//
// Created by benja on 18.12.2025.
//

#ifndef CHAININGHASHMAP_H
#define CHAININGHASHMAP_H

#include "MapItem.h"
#include "DynamicArray.h"

template <typename K, typename V> class ChainingHashMap {
private:
    DynamicArray<DynamicArray<MapItem<K, V>>> hashMap;


public:
};



#endif //CHAININGHASHMAP_H
