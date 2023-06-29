#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <sstream>
#include "catalog.hpp"
#include <forward_list>

/*I used forward list(likned list) in this context to pass a list of strings as input
to construct a Book object.
The constructor takes a pointer to a forward_list of strings, 
and the strings in the list are used to initialize the title,
authors, year, and tags member variables of the Book class.*/

using std::forward_list;
using std::string;
using std::stringstream;

namespace Catalog {
	class Book : public CatalogBase {
		public:
			// Default constructor
			Book();
		    // Copy constructor
		    Book(const Book &book);

		    // Constructor with individual fields
		    Book(const string &_title, const string &_authors, int _year, const string &_tags);

		    // Constructor with forward_list of strings
		    Book(const forward_list<string> *fields);

		    // Getters
		    string GetTitle() const;
		    string GetAuthors() const;
		    int GetYear() const;
		    string GetTags() const;

		    // Get the number of properties of a Book instance (title, authors, year, tags)
		    static int GetFieldCount();

		    // Compare functions for forward_list::sort()
		    static bool CompareTitle(const Book &book1, const Book &book2);
		    static bool CompareAuthors(const Book &book1, const Book &book2);
		    static bool CompareYear(const Book &book1, const Book &book2);
		    static bool CompareTags(const Book &book1, const Book &book2);

		    // Overloading stream insertion operator for output
		    friend stringstream &operator<<(stringstream &out, const Book &book);

		private:
		    string title;
		    string authors;
		    int year;
		    string tags;
	};
}

#endif //BOOK_HPP

