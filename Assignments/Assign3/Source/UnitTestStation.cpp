/*
    CS20006 Assignment 3
    UnitTestStation.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp UnitTestStation.cpp -o test
    ./test
*/

// Unit Testing File for class Station

// Including project header files
#include "Station.h"
#include "Railways.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Station::UnitTestStation()
{   
    // Testing the constructor
    const Station s1("Kolkata");
    assert("Kolkata" == s1.name_); // Check the name of the created object

    // Testing the copy constructor
    const Station s2(s1);
    assert("Kolkata" == s2.name_); // Check the name of the created object

    // Testing the GetName() function
    assert("Kolkata" == s1.GetName()); // Match the name with the expected name

    // Testing the GetDistance(.) function
    const Station s3("Delhi");
    assert(1472 == s1.GetDistance(s3)); // Check the distance between two stations

    // Testing the ostream operator
    stringstream out;
    out << s1;

    string expectedOutput = "Station : Kolkata";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << s1 << endl;

    // If the control has reached here, it means that all unit tests have passed
    cout << "\n*** ALL UNIT TESTS FOR CLASS Station PASSED ***\n";
}

int main()
{
    Station::UnitTestStation();

    return 0;
}