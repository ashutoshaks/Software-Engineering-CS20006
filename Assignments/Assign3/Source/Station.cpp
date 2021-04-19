/*
    CS20006 Assignment 3
    Station.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Station

// Including project header files
#include "Station.h"
#include "Railways.h"

Station::Station(const string& name) : name_(name)
{}

Station::Station(const Station& s) : name_(s.name_)
{}

Station::~Station()
{}

string Station::GetName() const
{
    return name_;
}

int Station::GetDistance(const Station& s) const
{   
    // Call the GetDistance() function of the Railways class to get the distance between the 2 stations
    return Railways::Type().GetDistance(*this, s);
}

ostream& operator<<(ostream& os, const Station& s)
{
    os << "Station : " << s.name_;
    return os;
}
