#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

using std::string;

namespace Exceptions {

    // Base class for exceptions
    class Exception {
    public:
        string what() const { return "base exception"; }
    };

    // Exception for missing field
    class MissingField : public Exception {
    public:
        string what() const { return "missing field"; }
    };

    // Exception for duplicate entry
    class DuplicateEntry : public Exception {
    public:
        string what() const { return "duplicate entry"; }
    };

    // Exception for wrong command
    class WrongCommand : public Exception {
    public:
        string what() const { return "command is wrong"; }
    };

    // Exception for blank method
    class BlankMethod : public Exception {
    public:
        string what() const { return "blank method"; }
    };
}

#endif // EXCEPTIONS_HPP
