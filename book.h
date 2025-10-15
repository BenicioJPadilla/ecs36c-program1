#pragma once
#include <string>
#include <ostream>

class Book{
    public :
    //the attributes of the book class
    int isbn{};
    std::string language;
    std::string quality;

    //will get the attributes of the book class from out csv files
    static Book fromCSV(const std::string& line);

    //overloading the comparison operators for our books class
    bool operator<(const Book& other) const;
    bool operator==(const Book& other) const;

    //overloading the output operator for our books class
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};