// test_main.cpp
// Glenn G. Chappell and Nicholas ALexeev
// 2019-09-02
//
// For CS 471 Fall 2021
// Includes main for catch and tests

#define CATCH_CONFIG_FAST_COMPILE
                             // Disable some features for faster compile
#define CATCH_CONFIG_RUNNER  // We write our own main
#include "catch.hpp"         // For the "Catch" unit-testing framework
#include "quicksort.hpp"
#include <iostream>          // For std::cout, endl, cin

TEST_CASE("Sort Empty List"){
	std::vector<int> data = {};
	sort(data,0,0);
	std::vector<int> sorted = {};
	REQUIRE(data==sorted);
}
TEST_CASE("Sort list of length 1"){
	std::vector<int> data = {0};
	sort(data,0,1);
	std::vector<int> sorted = {0};
	REQUIRE(data==sorted);
}
TEST_CASE("Sort list of length 10"){
	std::vector<int> data = {9,3,2,1,5,6,4,7,8,0};
	sort(data,0,data.size()-1);
	std::vector<int> sorted = {0,1,2,3,4,5,6,7,8,9};
	REQUIRE(data==sorted);
}

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    const std::string tname = "Sorting Algorythm";
                             // Printable name for this test suite
    Catch::Session session;  // Primary Catch object
    int catchresult;         // Catch return code; for return by main

    // Handle command line
    catchresult = session.applyCommandLine(argc, argv);

    if (!catchresult)  // Continue only if no command-line error
    {
        std::cout << "BEGIN tests for "
                  << tname << std::endl << std::endl;
        catchresult = session.run();
        std::cout << "END tests for "
                  << tname << std::endl << std::endl;
    }

    std::cout << "Press ENTER to quit ";
    userPause();

    return catchresult;
}


