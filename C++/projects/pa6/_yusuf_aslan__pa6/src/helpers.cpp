#include "helpers.hpp"
#include <forward_list>
#include <string>

using std::string;
using std::forward_list;

// Function definition for splitting a string into a forward_list of strings
forward_list<string>* SplitStringEncapsulated(const string& str, char delimiter) {
    forward_list<string>* split = new forward_list<string>(); // List of strings

    bool add = false; // Should current character be added to current string in list

    for (auto it = str.begin(); it != str.end(); ++it) { // Iterate through characters of string
        if (*it == delimiter) { // If delimiter is encountered
            add = !add; // Reverse add status
            if (add) // If new status is 'should be added'
                split->emplace_front(""); // Add new string to list
        } else if (add) { // If current character should already be added (not delimiter)
            split->front() += *it; // Add to current string
        }
    }

    return split;
}
