#ifndef USER_H
#define USER_H

#include <string>



namespace Authenticate {
    void inputUserName();
    std::string getUserName();
    namespace {

        std::string username;

        bool userIsValid() {
            return username.length() == 8;
        }

    }


}


#endif 
