#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include "book.h"
#include "search.h"


void testBookComparison() {
    Book book1{123, "English", "new"};
    Book book2{123, "English", "used"};
    Book book3{123, "Spanish", "new"};
    Book book4{124, "English", "new"};

    assert(book1 < book2); // new < used
    assert(book1 < book3); // English < Spanish
    assert(book1 < book4); // 123 < 124
    assert(!(book2 < book1));
    assert(!(book3 < book1));
    assert(!(book4 < book1));

    assert(book1 == book1);
    assert(!(book1 == book2));
}

void testLinearSearch() {
    std::vector<Book> books = {
        {123, "English", "new"},
        {124, "Spanish", "used"},
        {125, "French", "digital"}
    };

    Book searchBook{124, "Spanish", "used"};
    assert(linearSearch(books, searchBook) == true);

    Book notFoundBook{126, "German", "new"};
    assert(linearSearch(books, notFoundBook) == false);
}

void testBinarySearch() {
    std::vector<Book> books = {
        {123, "English", "new"},
        {124, "Spanish", "used"},
        {125, "French", "digital"}
    };
    std::sort(books.begin(), books.end());

    Book searchBook{124, "Spanish", "used"};
    assert(binarySearch(books, searchBook) == true);

    Book notFoundBook{126, "German", "new"};
    assert(binarySearch(books, notFoundBook) == false);
}

void testRecursiveBinarySearch() {
    std::vector<Book> books = {
        {123, "English", "new"},
        {124, "Spanish", "used"},
        {125, "French", "digital"}
    };
    std::sort(books.begin(), books.end());

    Book searchBook{124, "Spanish", "used"};
    assert(recursiveBinarySearch(books, searchBook, 0, books.size() - 1) == true);

    Book notFoundBook{126, "German", "new"};
    assert(recursiveBinarySearch(books, notFoundBook, 0, books.size() - 1) == false);
}

int main() {
    testBookComparison();
    testLinearSearch();
    testBinarySearch();
    testRecursiveBinarySearch();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}