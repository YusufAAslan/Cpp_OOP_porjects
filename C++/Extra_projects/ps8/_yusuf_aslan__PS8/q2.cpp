#include <iostream>
#include <string>

using namespace std;



template<typename T, typename U>
class Pair {
public:
    Pair(T first, U second);

    T getFirst() const;
    U getSecond() const;

    void setFirst(T first);
    void setSecond(U second);

private:
    T first;
    U second;
};



template<typename T, typename U>
Pair<T, U>::Pair(T first, U second) : first(first), second(second) {}

template<typename T, typename U>
T Pair<T, U>::getFirst() const {
    return first;
}

template<typename T, typename U>
U Pair<T, U>::getSecond() const {
    return second;
}

template<typename T, typename U>
void Pair<T, U>::setFirst(T first) {
    this->first = first;
}

template<typename T, typename U>
void Pair<T, U>::setSecond(U second) {
    this->second = second;
}



int main() {


    Pair<char, char> p('A', 'B');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('Z');
    cout << "First changed to " << p.getFirst() << endl;
    cout << "The pair is: " << p.getFirst() << ", " << p.getSecond() << endl;

    Pair<int, string> p2(34, "Bill");
    Pair<string, int> p3("Bill", 34);
    cout << "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;

    return 0;


}
