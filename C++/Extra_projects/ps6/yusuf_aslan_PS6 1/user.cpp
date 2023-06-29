#include <iostream>
#include "user.h"

namespace Authenticate {
    void inputUserName() {
        do {
            std::cout<<"Enter your username only 8  letters" << std::endl;
            std::cin>>username;
        } while (!userIsValid());
    }




    std::string getUserName() {

        return username;
    }


}

