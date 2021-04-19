/*
    CS20006 Assignment 5
    UnitTestDate.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Date.cpp Exceptions.cpp UnitTestDate.cpp -o test
    ./test
*/

// Unit Testing File for class Date

// Including project header files
#include "Date.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Date::UnitTestDate() { 
    /*
    * POSITIVE TEST CASES
    */

    // Testing the constructor
    Date d1(8, 4, 2021);
    assert(8 == d1.date_ && Apr == d1.month_ && 2021 == d1.year_); // Check the values of attributes of the created object

    Date d2(8, 4, 2021);

    // Testing the day() function
    assert(Thu == d1.day()); // Check for a normal date

    // Testing the CreateDate(...) function
    const Date* d3p = Date::CreateDate("9/4/2021");
    assert(9 == d3p -> date_ && Apr == d3p -> month_ && 2021 == d3p -> year_);

    const Date* d4p = Date::CreateDate("15/5/2022");
    
    const Date& d3 = *d3p;
    const Date& d4 = *d4p;

    Duration dur = d4 - d3;
    
    // Testing the ostream operator
    stringstream out;
    out << d1;

    string expectedOutput = "Thu, 8/Apr/2021";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << d1 << endl;

    out.str("");
    out << dur;
    expectedOutput = "1 years, 1 months, 6 days";
    assert(expectedOutput == out.str());

    try {
        const Date* dp = Date::CreateDate("29/2/2020");
        assert(29 == dp -> date_ && Feb == dp -> month_ && 2020 == dp -> year_);
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("29/2/2000");
        assert(29 == dp -> date_ && Feb == dp -> month_ && 2000 == dp -> year_);
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    cout << dur << endl;

    bool op1 = (d3 == d4);
    assert(false == op1);

    bool op2 = (d1 == d2);
    assert(true == op2);

    bool op3 = (d4 > d3);
    assert(true == op3);

    bool op4 = (d3 > d4);
    assert(false == op4);


    /*
    * NEGATIVE TEST CASES
    */

    try {
        const Date* dp = Date::CreateDate("29/02/2021");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("29/02/1900");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("31/04/2020");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("3104/2020");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("04/31/2020");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("11/03/1899");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }

    try {
        const Date* dp = Date::CreateDate("31/04/2100");
    } catch (Bad_Date& e) {
        cout << e.what() << endl;
    }
}

int main() {
    Date::UnitTestDate();

    return 0;
}