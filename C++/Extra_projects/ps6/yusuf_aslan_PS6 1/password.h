#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

namespace Authenticate
{
    namespace
    {
        bool isValid();
        std::string password;
        bool has_non_letter = false;
    }

    void inputPassword();
    std::string getPassword();

    namespace
    {
        bool isValid()
        {
            for (char letter : password) {
                if (!std::isalpha(letter)) {
                    has_non_letter = true;
                }
            }
            return (password.length() >= 8 && has_non_letter);
        }
    }
}

#endif
