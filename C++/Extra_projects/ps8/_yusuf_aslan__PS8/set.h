#ifndef SET_H
#define SET_H

#include <vector>

template<typename T>
class Set {
public:
    Set();
    void add(const T& item);
    int getSize() const;
    T* getArray() const;
private:
    std::vector<T> items;
};

#include "set.cpp"

#endif 
