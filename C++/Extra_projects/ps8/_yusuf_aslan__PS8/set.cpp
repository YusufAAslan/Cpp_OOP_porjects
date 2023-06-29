#include "set.h"

template<typename T>
Set<T>::Set() {}

template<typename T>
void Set<T>::add(const T& item) {
    for (const auto& i : items) {
        if (i == item) {
            return;
        }
    }
    items.push_back(item);
}

template<typename T>
int Set<T>::getSize() const {
    return items.size();
}

template<typename T>
T* Set<T>::getArray() const {
    if (items.empty()) {
        return NULL;
    }
    T* array = new T[items.size()];
    int i = 0;
    for (const auto& item : items) {
        array[i++] = item;
    }
    return array;
}
