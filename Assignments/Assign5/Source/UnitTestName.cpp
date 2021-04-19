/*
    CS20006 Assignment 5
    UnitTestName.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Name.cpp Exceptions.cpp UnitTestName.cpp -o test
    ./test
*/

// Unit Testing File for the Name class

// Including project header files
#include "Name.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Name::UnitTestName() {

    /*
    * POSITIVE TEST CASES
    */

    const Name n1("Ashutosh", "Kumar", "Singh");
    assert("Ashutosh" == n1.firstName_ && "Kumar" == n1.middleName_ && "Singh" == n1.lastName_);

    try {
        const Name* np1 = Name::CreateName("Ashutosh", "Kumar", "Singh");
        assert("Ashutosh" == np1 -> firstName_ && "Kumar" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Ashutosh", "", "Singh");
        assert("Ashutosh" == np1 -> firstName_ && "" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "", "Singh");
        assert("" == np1 -> firstName_ && "" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Ashutosh", "", "");
        assert("Ashutosh" == np1 -> firstName_ && "" == np1 -> middleName_ && "" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Ashutosh", "Kumar", "");
        assert("Ashutosh" == np1 -> firstName_ && "Kumar" == np1 -> middleName_ && "" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "Kumar", "Singh");
        assert("" == np1 -> firstName_ && "Kumar" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    stringstream out;
    out << n1;

    string expectedOutput = "Ashutosh Kumar Singh";
    assert(expectedOutput == out.str());


    /*
    * NEGATIVE TEST CASES
    */

    try {
        const Name* np1 = Name::CreateName("", "", "");
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "Kumar", "");
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }
}

int main() {
    Name::UnitTestName();

    return 0;
}