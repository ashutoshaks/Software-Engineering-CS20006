/*
    CS20006 Assignment 5
    UnitTestRailways.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestRailways.cpp -o test
    ./test
*/

// Unit Testing File for class Railways

// Including project header files
#include "Railways.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Railways::UnitTestRailways() {

    /*
    * POSITIVE TEST CASES
    */

    // Testing the IndianRailways() function (constructor automatically gets tested during this)
    // To test the singleton behaviour, we compare the addresses of the objects after calling Type() for the first and second time
    const Railways* firstPointer = &Railways::IndianRailways(); // First call
    const Railways* secondPointer = &Railways::IndianRailways(); // Second call
    assert(firstPointer == secondPointer); // Compare both the addresses for equality

    // Testing the GetDistance(., .) function
    assert(1871 == Railways::IndianRailways().GetDistance(Station("Bangalore"), Station("Kolkata"))); // Match the distance between 2 stations
    assert(1871 == Railways::IndianRailways().GetDistance(Station("Kolkata"), Station("Bangalore")));

    // Testing the GetStation(...) function
    const Station* sp = Railways::IndianRailways().GetStation("Mumbai");
    assert("Mumbai" == sp -> GetName());

    // Testing the ostream operator
    stringstream out;
    out << Railways::IndianRailways();

    string expectedOutput = "Indian Railways\n\nList of Stations\nStation : Mumbai\nStation : Delhi\nStation : Bangalore\nStation : Kolkata\n"
                            "Station : Chennai\n\nPairwise Distances\nBangalore - Chennai = 350 km\nBangalore - Kolkata = 1871 km\n"
                            "Delhi - Bangalore = 2150 km\nDelhi - Chennai = 2180 km\nDelhi - Kolkata = 1472 km\nKolkata - Chennai = 1659 km\n"
                            "Mumbai - Bangalore = 981 km\nMumbai - Chennai = 1338 km\nMumbai - Delhi = 1447 km\nMumbai - Kolkata = 2014 km\n";

    assert(expectedOutput == out.str()); // Match the output with the expected output

    // Also print the object to the screen for better clarity
    cout << Railways::IndianRailways() << endl;


    /*
    * NEGATIVE TEST CASES
    */

    // Testing the GetStation(., .) function
    try {
        const Station* sp = Railways::IndianRailways().GetStation("Bombay");
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
    }

}

int main() {
    Railways::UnitTestRailways();

    return 0;
}