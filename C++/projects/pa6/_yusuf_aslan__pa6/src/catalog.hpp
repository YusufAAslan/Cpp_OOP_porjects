#ifndef CATALOG_HPP
#define CATALOG_HPP

#include "exceptions.hpp"
#include <string>

using std::string;
using Exceptions::BlankMethod;

namespace Catalog {

    // This class serves as a base class for the Book, Music, and Movie classes.
    // It contains member methods that will not execute in the current state of the code.
    // This class is necessary for template functions to work properly with the derived classes.
    class CatalogBase {
        public:
            // Getter methods that throw a BlankMethod exception
            string GetTitle() const { throw BlankMethod(); }
            string GetAuthors() const { throw BlankMethod(); }
            string GetYear() const { throw BlankMethod(); }
            string GetTags() const { throw BlankMethod(); }
            string GetArtists() const { throw BlankMethod(); }
            string GetGenre() const { throw BlankMethod(); }
            string GetDirector() const { throw BlankMethod(); }
            string GetStarring() const { throw BlankMethod(); }

            // Compare methods that throw a BlankMethod exception
            static bool CompareTitle(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareAuthors(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareYear(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareTags(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareArtists(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareGenre(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareDirector(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
            static bool CompareStarring(const CatalogBase& cb1, const CatalogBase& cb2) { throw BlankMethod(); }
    };

}

#endif // CATALOG_HPP
