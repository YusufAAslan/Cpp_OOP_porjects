#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <forward_list>

using std::forward_list;
using std::string;

// Function declaration for splitting a string into a forward_list of strings 
forward_list<string>* SplitStringEncapsulated(const string& str, char delimiter);

#endif // HELPERS_HPP
