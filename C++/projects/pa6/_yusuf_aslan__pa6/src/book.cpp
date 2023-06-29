// The implementations of book.hpp

#include "book.hpp"
#include <string>
#include <forward_list>
#include <sstream>

namespace Catalog 
{
    Book::Book() : title{}, authors{}, year{}, tags{} {
    // Default constructor implementation
    }


    Book::Book(const Book &book) : title(book.title), authors(book.authors), year(book.year), tags(book.tags) {
        // Copy constructor implementation
    }

    Book::Book(const std::string &_title, const std::string &_authors, int _year, const std::string &_tags)
        : title(_title), authors(_authors), year(_year), tags(_tags) {
        // Constructor with individual fields implementation
    }

    Book::Book(const std::forward_list<std::string> *fields) {
        auto it = fields->begin();
        tags = *it++;
        year = std::stoi(*it++);
        authors = *it++;
        title = *it++;
        // Constructor with forward_list of strings implementation
    }

    std::string Book::GetTitle() const {
        return title;
    }

    std::string Book::GetAuthors() const {
        return authors;
    }

    int Book::GetYear() const {
        return year;
    }

    std::string Book::GetTags() const {
        return tags;
    }

    int Book::GetFieldCount() {
        return 4;
    }

    bool Book::CompareTitle(const Book &book1, const Book &book2) {
        return book1.title < book2.title;
    }

    bool Book::CompareAuthors(const Book &book1, const Book &book2) {
        return book1.authors < book2.authors;
    }

    bool Book::CompareYear(const Book &book1, const Book &book2) {
        return book1.year < book2.year;
    }

    bool Book::CompareTags(const Book &book1, const Book &book2) {
        return book1.tags < book2.tags;
    }

    std::stringstream &operator<<(std::stringstream &out, const Book &book) {
        out << '"' << book.title << "\" \"" << book.authors << "\" \"" << book.year << "\" \""
            << book.tags << '"' << std::endl;
        return out;
    }
}