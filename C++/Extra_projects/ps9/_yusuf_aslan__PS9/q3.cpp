#include <iostream>
#include "stack.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{


    cout << "This program tests the Stack class.\n";
    char ans;


    do
    {

        Stack<int> stack;
        cout << "Enter up to 5 integers (-1 to stop): ";
        int num;
        cin >> num;

        try
        {
            while (num != -1)
            {
                stack.push(num);
                cin >> num;
            }
        }
        catch (const PopEmptyStackException& e)
        {
            cout << "Exception caught: " << e.what() << endl;
        }

        cout << "Popping elements from the stack: ";


        try
        {
            while (!stack.isEmpty())
            {
                cout << stack.pop() << " ";
            }
            cout << endl;
        }
        catch (const PopEmptyStackException& e)
        {
            cout << "Exception caught: " << e.what() << endl;
        }

            cout << "Test again? (y/n) ";
            cin >> ans;


    } while (ans == 'y' || ans == 'Y');



    return 0;
}

