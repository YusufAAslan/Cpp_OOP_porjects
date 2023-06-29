#include <iostream>
#include "password.h"

namespace Authenticate {


    void inputPassword() {

        do {

            std::cout << "Enter password but at least 8 characters and contains  one non char !!)" << std::endl;
            std::cin >> password;

        } while (!isValid());


    }

    std::string getPassword() {
        return password;
    }
}
