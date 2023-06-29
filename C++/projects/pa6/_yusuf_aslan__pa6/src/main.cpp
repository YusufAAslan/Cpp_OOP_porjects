#include "movie.hpp"
#include "book.hpp"
#include "music.hpp"
#include "helpers.hpp"
#include "templates.hpp"
#include <iostream>
#include <forward_list>
#include <string>
#include <fstream>

using namespace std;
using Catalog::Book;
using Catalog::Music;
using Catalog::Movie;



int main() {
    // Files needed for operations
    ifstream dataFile("data.txt");
    ofstream outputFile("output.txt");
    ifstream commandFile("commands.txt");

    // Catalog type has to be read beforehand
    string catalogType;
    getline(dataFile, catalogType);

    // Print the catalog type read
    outputFile << "Catalog Read: " << catalogType << "\n";

    // Declare and initialize the data list based on the catalog type
    if (catalogType == "book") {
        forward_list<Book> dataList; // List of books specified in the data file
        ReadData<Book>(dataFile, dataList, outputFile); // Read data file and fill data list
        ExecuteCommands<Book>(commandFile, dataList, outputFile); // Execute commands
    } else if (catalogType == "music") {
        forward_list<Music> dataList; // List of music specified in the data file
        ReadData<Music>(dataFile, dataList, outputFile); // Read data file and fill data list
        ExecuteCommands<Music>(commandFile, dataList, outputFile); // Execute commands
    } else if (catalogType == "movie") {
        forward_list<Movie> dataList; // List of movies specified in the data file
        ReadData<Movie>(dataFile, dataList, outputFile); // Read data file and fill data list
        ExecuteCommands<Movie>(commandFile, dataList, outputFile); // Execute commands
    } else { // If catalog type doesn't match any of the types
        outputFile << "Invalid catalog type: " << catalogType << endl;
    }

    // Close files
    dataFile.close();
    outputFile.close();
    commandFile.close();

    return 0;
}   


    