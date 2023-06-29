#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include "exceptions.hpp"
#include "helpers.hpp"
#include <fstream>
#include <forward_list>
#include <string>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::forward_list;
using std::getline;
using std::string;
using std::stringstream;
using Exceptions::MissingField;
using Exceptions::DuplicateEntry;
using Exceptions::WrongCommand;
using Exceptions::BlankMethod;

// Reads lines from a given file and fills the given list with data from the read lines
template <typename T>
void ReadData(ifstream& in, forward_list<T>& list, ofstream& out) {
    string readLine;                        // Read line
    int uniqueEntries = 0;                   // Number of unique entries
    string firstField;                       // First read field
    forward_list<string>* fields;            // Fields
    int fieldCount;                          // Number of fields

    while (getline(in, readLine)) {
        fields = SplitStringEncapsulated(readLine, '"');  // Get fields
        fieldCount = 0;                                 // Reset number of fields

        try {
            for (auto it = fields->begin(); it != fields->end(); ++it) {    // Iterate through field list
                firstField = *it;       // First field is at the end of the list, so update it each iteration
                ++fieldCount;           // Increase number of fields each time, representing the size of the field list
            }

            if (fieldCount != T::GetFieldCount())    // If the number of fields doesn't match with the specified class's
                throw MissingField();                // There's a missing field
        } catch (MissingField e) {
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;
            delete fields;                          // Deallocate
            continue;                               // Move to the next line of the data file
        }

        try {
            for (auto it = list.begin(); it != list.end(); ++it) {    // For each element of the list
                if (it->GetTitle() == firstField)                     // Check if current instance's title matches any
                    throw DuplicateEntry();                           // If so, there's a duplicate entry error
            }
        } catch (DuplicateEntry e) {
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;
            delete fields;                                      // Deallocate
            continue;                                           // Move to the next line of the data file
        }

        ++uniqueEntries;                                // Increase the number of unique entries
        list.emplace_front(fields);                     // Add the instance to the list
        delete fields;                                  // Deallocate
    }

    out << uniqueEntries << " unique entries\n";        // Inform about the number of unique entries
}

// Reads a command file and executes it with the given list of data
template <typename T>
void ExecuteCommands(ifstream& in, forward_list<T>& dataList, ofstream& out) {
    string readLine;                            // Read line from the data file
    forward_list<string>* fields;               // Field list of the read line

    while (getline(in, readLine)) {
        stringstream streamReadLine(readLine);                  // Create a stream of the read line to extract the command (not surrounded by quotation marks)
        stringstream commandResult;                             // Result string of the command
        fields = SplitStringEncapsulated(readLine, '"');        // Get fields
        auto commandArg = fields->begin();                      // Command's argument iterator

        string command;                                         // Command
        streamReadLine >> command;                              // Get the command
        string searchField = *commandArg++;                      // The field in which the search or sort will be done

        try {
            if (command == "search") {                           // If the command is to search
                string searched = *commandArg++;                 // What will be searched

                // Search in the corresponding field
                // Iterate through the list elements and add any matching element to the command result string
                if (searchField == "title") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetTitle().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "authors") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetAuthors().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "year") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (std::to_string(it->GetYear()).find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "tags") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetTags().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "artists") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetArtists().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "genre") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetGenre().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "director") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetDirector().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else if (searchField == "starring") {
                    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
                        if (it->GetStarring().find(searched) != string::npos)
                            commandResult << *it;
                    }
                } else {    // If the search field is something different
                    throw WrongCommand();   // Then the command is wrong
                }
            } else if (command == "sort") {     // If the command is to sort
                // Sort the data list accordingly
                if (searchField == "title")
                    dataList.sort(T::CompareTitle);
                else if (searchField == "authors")
                    dataList.sort(T::CompareAuthors);
                else if (searchField == "year")
                    dataList.sort(T::CompareYear);
                else if (searchField == "tags")
                    dataList.sort(T::CompareTags);
                else if (searchField == "artists")
                    dataList.sort(T::CompareArtists);
                else if (searchField == "genre")
                    dataList.sort(T::CompareGenre);
                else if (searchField == "director")
                    dataList.sort(T::CompareTitle);
                else if (searchField == "starring")
                    dataList.sort(T::CompareTitle);
                else    // If the field is something else
                    throw WrongCommand();   // Then the command is wrong

                // Iterate through the sorted list and add instances to the command result
                for (auto it = dataList.begin(); it != dataList.end(); ++it)
                    commandResult << *it;
            }
        }

        // Since this function is a template, it should work for each of Movie book music .
        // Thus, to satisfy the compiler, the base class has every getter and compare function with a blank method throw.
        // This catch block is for that.
        catch (BlankMethod e) {
            throw WrongCommand();
        }
        catch (WrongCommand e) {    // Inform about the wrong command error
            out << "Exception: " << e.what() << std::endl
                << readLine << std::endl;
            delete fields;    // Deallocate
            continue;    // Get to the next line of the command file
        }

        out << readLine << std::endl    // Write wanted line to read or the command 
            << commandResult.str();    // Write the command result
        delete fields;    // Deallocate
    }
}

#endif // TEMPLATES_HPP
