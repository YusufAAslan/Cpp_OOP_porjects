// This program tests the class PFArrayD.

#include <iostream>
#include "pfarrayd.h"

using std::cin;
using std::cout;
using std::endl;

void testPFArrayD();

int main()
{
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do
    {
        testPFArrayD();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " non-negative numbers.\n";
    cout << "Place a negative number at the end.\n";
    double next;
    cin >> next;

    try
    {
        while (next >= 0 && !temp.full())
        {
            temp.addElement(next);
            cin >> next;
        }
    }
    catch (const OutOfRange& e)
    {
        cout << "Exception caught: Index " << e.getIndex() << " is out of range." << endl;
    }

    cout << "You entered the following " << temp.getNumberUsed() << " numbers:\n";
    for (int index = 0; index < temp.getNumberUsed(); index++)
    {
        cout << temp[index] << " ";
    }
    cout << "(plus a sentinel value.)\n";
    // Test index out of range
    try
    {
        cout << temp[-1]; // 2 * count];
    }
    catch (const OutOfRange& e)
    {
        cout << "Exception caught: Index " << e.getIndex() << " is out of range." << endl;
    }
    // Test insert beyond declared size
    try
    {
        temp.addElement(99999);
    }
    catch (const OutOfRange& e)
    {
        cout << "Exception caught: Index " << e.getIndex() << " is out of range." << endl;
    }
}
