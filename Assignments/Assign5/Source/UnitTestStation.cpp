/*
    CS20006 Assignment 5
    UnitTestStation.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestStation.cpp -o test
    ./test
*/

// Unit Testing File for class Station

// Including project header files
#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Station::UnitTestStation() {

    /*
    * POSITIVE TEST CASES
    */

    // Testing the constructor
    const Station s1("Kolkata");
    assert("Kolkata" == s1.name_); // Check the name of the created object

    // Testing the CreateStation(...) function
    const Station* sp = Station::CreateStation("Mumbai");
    assert("Mumbai" == sp -> name_);

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


    /*
    * NEGATIVE TEST CASES
    */

    // Testing the CreateStation(...) function
    // Try to create a Station object with the name as an empty string
    try {
        const Station* spt = Station::CreateStation("");
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
    }
}

int main() {
    Station::UnitTestStation();

    return 0;
}