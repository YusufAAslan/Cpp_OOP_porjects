#include <iostream>



void recursiveFunction(int level);



int main() {
    int level;
    std::cout << "Enter the level at which you want the exception to be thrown (0-10): ";
    std::cin >> level;

    try {
        recursiveFunction(level);
    }
    catch (const char* msg) {
        std::cout << "Caught exception: " << msg << std::endl;
    }

    return 0;
}


void recursiveFunction(int level) {
    if (level == 0) {
        throw "Exception thrown at level 0";
    }
    else if (level == 10) {
        return;
    }
    else {
        try {
            recursiveFunction(level + 1);
        }
        catch (const char* msg) {
            std::cout << "Caught exception: " << msg << std::endl;
        }
    }
}