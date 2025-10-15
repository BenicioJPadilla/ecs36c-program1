#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "book.h"
#include "search.h"
#include <algorithm>

int main(int argc, char* argv[]) {
    //makes sure that the user inputs the correct number of arguments
    //lets them know they used the correct files
    if (argc < 3) {
        std::cerr << "Usage: " << "./searchnewbooks" << " <newbooks.dat> <request.dat>" << std::endl;
        return 1;
    }

    //reads in the files as strings that we will be able to use
    const std::string newbooks_file = argv[1];
    const std::string request_file = argv[2];

    //creating file that will later output the found files
    const std::string foundbooks_file = "foundbooks.dat";

    //opens the files
    std::ifstream newbooks(newbooks_file);

    //checks to make sure the files opened correctly
    if(!newbooks){
        std::cerr << "Error: could not open file " << newbooks_file << std::endl;
        return 1;
    }

    //opens the request file
    std::ifstream request(request_file);

    //checks to make sure the request file opened correctly
    if(!request){
        std::cerr << "Error: could not open file " << request_file << std::endl;
        return 1;
    }

    //vectors to hold the books from the files
    std::vector<Book> newBooksList, requestList;
    //string to hold each line of the files as we read them in
    std::string line;

    while(std::getline(newbooks, line)){
        if (!line.empty()) {
            try {
                //parsing each line of the file into a book object and adding it to the vector
                newBooksList.push_back(Book::fromCSV(line));
            } catch (const std::invalid_argument& e) {
                //outputting an error if the line is invalid
                std::cerr << "Skipping invalid line in " << newbooks_file << ": " << line << std::endl;
            }
        }
    }
    while(std::getline(request, line)){
        if (!line.empty()) {
            try {
                //parsing each line of the file into a book object and adding it to the vector
                requestList.push_back(Book::fromCSV(line));
            } catch (const std::invalid_argument& e) {
                //outputting an error if the line is invalid
                std::cerr << "Skipping invalid line in " << request_file << ": " << line << std::endl;
            }
        }
    }



    std::ofstream foundbooks(foundbooks_file);


    char choice = 0;
    while(true) {
        std::cout << "What is your search method? ([L]inear, [B]inary, [R]ecursiveBinary): ";
        std::cin >> choice;
        if (choice == 'L' || choice == 'l' || choice == 'B' || choice == 'b' || choice == 'R' || choice == 'r') {
            break;
        }
        std::cerr << "Invalid choice. Please enter L, B, or R." << std::endl;
    }

    int found = 0;
    Timer timer;
    timer.reset();

    //linear search
    if(choice == 'L' || choice == 'l') {
        //iterating through the request list and searching for each book in the new books list
        for (const auto& req : requestList) {
            //if found we add to our found
            if (linearSearch(newBooksList, req)) {
                found++;
            }

        }
    }
    else {
        //sorting the new books list for binary search
        std::sort(newBooksList.begin(), newBooksList.end());
        //binary search
        if (choice == 'B' || choice == 'b') {
            //iterating through the request list and searching for each book in the new books list
            for (const auto& req : requestList) {
                //if found we add to our found
                if (binarySearch(newBooksList, req)) {
                    found++;
                }

            }
        }
        else {
            //recursive binary search
            //iterating through the request list and searching for each book in the new books list
            for (const auto& req : requestList) {
                //if found we add to our found
                if (recursiveBinarySearch(newBooksList, req, 0, newBooksList.size() - 1)) {
                    found++;
                }

            }
        }   
    }

    double used = timer.elapsed();
    std::cout << "CPU time: " << used << " microseconds" << std::endl;

    std::ofstream out(foundbooks_file);
    out << found << "\n";



}