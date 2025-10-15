#include "search.h"

bool linearSearch(const std::vector<Book>& newBooksList, const Book& requestBook) {
    //iterating through the new books list to find the requested book
    for (const auto& book : newBooksList) {
        if (book == requestBook) {
            return true; // Book found
        }
    }
    return false; // Book not found
};

bool binarySearch(const std::vector<Book>& newBooksList, const Book& requestBook) {
    int lo = 0;
    int hi = newBooksList.size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if(newBooksList[mid] == requestBook){
            return true; // Book found
        } else if (newBooksList[mid] < requestBook) {
            lo = mid + 1; // Search in the right half
        } else {
            hi = mid - 1; // Search in the left half
        }
    }

    return false; // Book not found

};

bool recursiveBinarySearch(const std::vector<Book>& newBooksList, const Book& requestBook, int lo, int hi) {
    if (lo > hi) {
        return false; // Base case: Book not found
    }

    int mid = (lo + hi) / 2;

    if (newBooksList[mid] == requestBook) {
        return true; // Book found
    } else if (newBooksList[mid] < requestBook) {
        return recursiveBinarySearch(newBooksList, requestBook, mid + 1, hi); // Search in the right half
    } else {
        return recursiveBinarySearch(newBooksList, requestBook, lo, mid - 1); // Search in the left half
    }
};