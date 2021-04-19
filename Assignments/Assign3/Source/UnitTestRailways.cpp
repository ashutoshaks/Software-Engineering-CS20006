/*
    CS20006 Assignment 3
    UnitTestRailways.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp UnitTestRailways.cpp -o test
    ./test
*/

// Unit Testing File for class Station

// Including project header files
#include "Railways.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Railways::UnitTestRailways()
{   
    // Testing the Type() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const Railways* firstPointer = &Railways::Type(); // First call
    const Railways* secondPointer = &Railways::Type(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    const Railways& IndianRailways = Railways::Type();

    // Testing the GetDistance(., .) function
    assert(1871 == IndianRailways.GetDistance(Station("Bangalore"), Station("Kolkata"))); // Match the distance between 2 stations

    // Testing the ostream operator
    stringstream out;
    out << IndianRailways;

    string expectedOutput = "Indian Railways\n\nList of Stations\nStation : Mumbai\nStation : Delhi\nStation : Bangalore\nStation : Kolkata\n"
                            "Station : Chennai\n\nPairwise Distances\nBangalore - Chennai = 350 km\nBangalore - Delhi = 2150 km\n"
                            "Bangalore - Kolkata = 1871 km\nBangalore - Mumbai = 981 km\nChennai - Delhi = 2180 km\nChennai - Kolkata = 1659 km\n"
                            "Chennai - Mumbai = 1338 km\nDelhi - Kolkata = 1472 km\nDelhi - Mumbai = 1447 km\nKolkata - Mumbai = 2014 km\n";
    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << IndianRailways << endl;

    // If the control has reached here, it means that all unit tests have passed
    cout << "*** ALL UNIT TESTS FOR CLASS Railways PASSED ***\n";
}

int main()
{
    Railways::UnitTestRailways();

    return 0;
}