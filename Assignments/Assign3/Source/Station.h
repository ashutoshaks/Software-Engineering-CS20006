/*
    CS20006 Assignment 3
    Station.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for class Station

#ifndef __STATION_H // Control inclusion of header files
#define __STATION_H

// C++ Headers
#include <iostream>
using namespace std;

// Class Declaration for the Station class - a simple data class
class Station
{
private:
    const string name_;

    Station& operator=(const Station&); // Blocked copy assignment operator
    
public:
    Station(const string&); // Constructor
    Station(const Station&); // Copy Constructor
    ~Station(); // Destructor
    string GetName() const; // Getter function to get the name of a Station
    int GetDistance(const Station&) const; // Function to get distance from one Station to another
    friend ostream& operator<<(ostream&, const Station&); // Output streaming operator
    static void UnitTestStation(); // Static function for unit testing
};

#endif // __STATION_H
