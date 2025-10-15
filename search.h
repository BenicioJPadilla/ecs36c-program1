#pragma once
#include <string>
#include <vector>
#include "book.h"
#include <chrono>

bool linearSearch(const std::vector<Book>& newBooksList, const Book& requestBook);
bool binarySearch(const std::vector<Book>& newBooksList, const Book& requestBook);
bool recursiveBinarySearch(const std::vector<Book>& newBooksList, const Book& requestBook, int lo, int hi);

class Timer {
    //type alias for high resolution clock
    using clk = std::chrono::high_resolution_clock;
    //variable to hold the start time point
    clk::time_point start;
    public:
    //constructor that starts the timer
    void reset() { start = clk::now();  }
    double elapsed() const {
        auto now = clk::now();
        return std::chrono::duration<double, std::micro>(now - start).count();
    }

};
