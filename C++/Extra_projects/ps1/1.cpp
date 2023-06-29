#include <iostream>
using namespace std;
 

bool isPrime(int n);


int main()
{
    int N = 100;
 
    // check for every number from 3 to N
    for (int i = 3; i <= N; i++) {
        // check if current number is prime
        if (isPrime(i))
            cout << i << " ";
    }
    cout<<endl;
 
    return 0;
}


bool isPrime(int n)
{
    // since 0 and 1 is not prime return false.
    if (n == 1 || n == 0)
        return false;
 
    // Run a loop from 2 to n-1
    for (int i = 2; i < n; i++) {
        // if the number is divisible by i, then n is not a
        // prime number.
        if (n % i == 0)
            return false;
    }
    // otherwise, n is prime number.
    return true;
}