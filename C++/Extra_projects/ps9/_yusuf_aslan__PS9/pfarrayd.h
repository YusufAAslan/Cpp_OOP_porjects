#ifndef PFARRAYD_H
#define PFARRAYD_H

#include <string>

class Exception
{
};

class OutOfRange : public Exception
{
public:
    OutOfRange(const std::string& thisMessage, int thisIndex);
    int getIndex() const;

private:
    int index;
};

class PFArrayD
{
public:
    PFArrayD();
    PFArrayD(int capacityValue);
    PFArrayD(const PFArrayD& pfArrayObject);
    void addElement(double element);
    bool full() const { return (capacity == used); }
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray() { used = 0; }
    double& operator[](int index);
    PFArrayD& operator=(const PFArrayD& rightSide);
    ~PFArrayD();

private:
    double* a;
    int capacity;
    int used;
};

#endif // PFARRAYD_H
