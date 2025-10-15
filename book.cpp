#include <iostream>
#include <string>
#include "book.h"
#include <fstream>
#include <sstream>

//function to rank the quality of the book for comparison purposes
static inline int qualityRank(const std::string& quality) {
    if (quality == "new") return 0; // new
    if (quality == "used") return 1; // used
    else return 2; // digital or other
}

Book Book::fromCSV(const std::string& line){
    Book book;

    //parsing the csv file to get the attributes of the book class
    std::string a, language, quality;
    std::stringstream ss(line);

    //getting the attributes from the csv file and assigning them to the book class
    if (std::getline(ss, a, ',') && std::getline(ss, language, ',') && std::getline(ss, quality)){
    
        if (!quality.empty() && quality.back() == '\r') quality.pop_back();
            // string to integer conversion for the isbn
            book.isbn = std::stoi(a);
            book.language = language;
            book.quality = quality;
    }
    else
        {
            throw std::invalid_argument("Invalid CSV format");
        }

        return book;
    }

//overloading the output operator for our books class
bool Book::operator<(const Book& other) const {
    //if they are not the same isbn, langauge, or quality, return false
    if (isbn != other.isbn)
        return isbn < other.isbn;
    int r1 = qualityRank(quality), r2 = qualityRank(other.quality);
    if (r1 != r2) return r1 < r2;     // type order first
    return language < other.language; // then language
}
//overloading the equality operator for our books class
bool Book::operator==(const Book& other) const {
    //if they are the same isbn, langauge, and quality, return true
    return isbn == other.isbn && language == other.language && quality == other.quality;
}

//overloading the output operator for our books class
std::ostream& operator<<(std::ostream& os, const Book& book) {
    //outputting the attributes of the book class in csv format
    os << book.isbn << "," << book.language << "," << book.quality;
    return os;
}