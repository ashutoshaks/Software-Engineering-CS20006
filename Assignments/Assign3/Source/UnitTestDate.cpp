/*
    CS20006 Assignment 3
    UnitTestDate.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Date.cpp UnitTestDate.cpp -o test
    ./test
*/

// Unit Testing File for class Date

// Including project header files
#include "Date.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Date::UnitTestDate()
{   
    // Testing the constructor
    Date d1(7, 3, 2021);
    assert(7 == d1.date_ && Mar == d1.month_ && 2021 == d1.year_); // Check the values of attributes of the created object

    // Testing the copy constructor
    Date d2(d1);
    assert(7 == d2.date_ && Mar == d2.month_ && 2021 == d2.year_); // Check the values of attributes of the created object

    // Testing the day() function
    assert(Sun == d1.day()); // Check for a normal date

    Date d3(29, 2, 2020);
    assert(Sat == d3.day()); // Check for a 29th February

    // Testing the ostream operator
    stringstream out;
    out << d1;

    string expectedOutput = "Sun, 7/Mar/2021";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << d1 << endl;

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS Date PASSED ***\n";
}

int main()
{
    Date::UnitTestDate();

    return 0;
}