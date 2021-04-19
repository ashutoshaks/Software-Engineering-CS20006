/*
    CS20006 Assignment 3
    Railways.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for Station class

// Including project header files
#include "Railways.h"

// Initializing the static constants
const vector<Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"), Station("Bangalore"), Station("Kolkata"), Station("Chennai")};

const map<pair<string, string>, int> Railways::sDistStations = {{{"Mumbai", "Delhi"}, 1447}, {{"Delhi", "Mumbai"}, 1447}, {{"Mumbai", "Bangalore"}, 981}, {{"Bangalore", "Mumbai"}, 981}, 
    {{"Mumbai", "Kolkata"}, 2014}, {{"Kolkata", "Mumbai"}, 2014}, {{"Mumbai", "Chennai"}, 1338}, {{"Chennai", "Mumbai"}, 1338}, {{"Delhi", "Bangalore"}, 2150}, {{"Bangalore", "Delhi"}, 2150},
    {{"Delhi", "Kolkata"}, 1472}, {{"Kolkata", "Delhi"}, 1472}, {{"Delhi", "Chennai"}, 2180}, {{"Chennai", "Delhi"}, 2180}, {{"Bangalore", "Kolkata"}, 1871}, {{"Kolkata", "Bangalore"}, 1871},
    {{"Bangalore", "Chennai"}, 350}, {{"Chennai", "Bangalore"}, 350}, {{"Kolkata", "Chennai"}, 1659}, {{"Chennai", "Kolkata"}, 1659}};

Railways::Railways()
{}

Railways::~Railways()
{}

const Railways& Railways::Type()
{
    static const Railways theObj;
    return theObj; 
}

int Railways::GetDistance(const Station& fromStation, const Station& toStation) const
{
    return Railways::sDistStations.at({fromStation.GetName(), toStation.GetName()});
}

ostream& operator<<(ostream& os, const Railways& IndianRailways)
{
    // Here we print all the stations and the pairwise distances between the stations
    os << "Indian Railways\n\n";
    os << "List of Stations\n";
    vector<Station>::const_iterator it;
    for(it = Railways::sStations.begin(); it != Railways::sStations.end(); it++)
    {
        os << (*it) << endl;
    }
    os << "\nPairwise Distances\n";

    set<pair<string, string>> occurred; // To ensure the pairs are not printed twice
    map<pair<string, string>, int>::const_iterator iter;
    for(iter = Railways::sDistStations.begin(); iter != Railways::sDistStations.end(); iter++)
    {
        string s1 = (iter -> first).first;
        string s2 = (iter -> first).second;
        if(!occurred.count({s2, s1})) // If the pair has not occurred before then print it and insert it in the set
        {
            os << s1 << " - " << s2 << " = " << iter -> second << " km\n";
            occurred.insert({s1, s2});
        }
    }
    return os;
}
