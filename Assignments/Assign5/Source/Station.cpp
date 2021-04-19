/*
    CS20006 Assignment 5
    Station.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Station

// Including project header files
#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"

Station::Station(const string& name) : name_(name) {}

const Station* Station::CreateStation(const string& name) {
    if(name == "")
        throw Bad_Station("Station name cannot be empty");
    return new Station(name);
}

string Station::GetName() const {
    return name_;
}

int Station::GetDistance(const Station& s) const {   
    // Call the GetDistance() function of the Railways class to get the distance between the 2 stations
    return Railways::IndianRailways().GetDistance(*this, s);
}

ostream& operator<<(ostream& os, const Station& s) {
    os << "Station : " << s.name_;
    return os;
}
