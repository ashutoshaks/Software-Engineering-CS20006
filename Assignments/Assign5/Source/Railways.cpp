/*
    CS20006 Assignment 5
    Railways.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for Railways class

// Including project header files
#include "Railways.h"

// Initializing the static constants
const vector<const Station*> Railways::sStations = {new Station("Mumbai"), new Station("Delhi"), new Station("Bangalore"), new Station("Kolkata"), new Station("Chennai")};

const map<pair<string, string>, int> Railways::sDistStations = 
{
{{"Mumbai", "Delhi"}, 1447}, 
{{"Mumbai", "Bangalore"}, 981}, 
{{"Mumbai", "Kolkata"}, 2014}, 
{{"Mumbai", "Chennai"}, 1338}, 
{{"Delhi", "Bangalore"}, 2150}, 
{{"Delhi", "Kolkata"}, 1472},
{{"Delhi", "Chennai"}, 2180}, 
{{"Bangalore", "Kolkata"}, 1871}, 
{{"Bangalore", "Chennai"}, 350}, 
{{"Kolkata", "Chennai"}, 1659}, 
};

const Railways& Railways::IndianRailways() {
    for(size_t i = 0; i < Railways::sStations.size(); i++) {
        for(size_t j = i + 1; j < Railways::sStations.size(); j++) {
            if(Railways::sStations[i] -> GetName() == Railways::sStations[j] -> GetName())
                throw Duplicate_Station("Station - " + Railways::sStations[i] -> GetName() + " is duplicated");
        }
    }

    map<pair<string, string>, int>::const_iterator it;
    for(it = Railways::sDistStations.begin(); it != Railways::sDistStations.end(); it++) {
        if(Railways::sDistStations.find({(it -> first).second, (it -> first).first}) != Railways::sDistStations.end())
            throw Duplicate_Pair((it -> first).second + " - " + (it -> first).first + " is a duplicate pair");
    }

    static const Railways theObj;
    return theObj; 
}

int Railways::GetDistance(const Station& fromStation, const Station& toStation) const {
    map<pair<string, string>, int>::const_iterator it;
    // Check the from-to pair
    it = Railways::sDistStations.find({fromStation.GetName(), toStation.GetName()});
    if (it == Railways::sDistStations.end()) { // Does not exist
        // Check the to-from pair. Must exist by symmetry
        it = Railways::sDistStations.find({toStation.GetName(), fromStation.GetName()});
    }
    return it -> second;
}

const Station* Railways::GetStation(const string& name) const {
    vector<const Station*>::const_iterator it;
    for (it = Railways::sStations.begin(); it != Railways::sStations.end(); ++it) {
        if ((*it) -> GetName() == name)
            break;
    }
    if(it == Railways::sStations.end())
        throw Bad_Station("Station name is invalid : " + name);

    return (*it);
}

ostream& operator<<(ostream& os, const Railways& IndianRailways) {
    // Here we print all the stations and the pairwise distances between the stations
    os << "Indian Railways\n\n";
    os << "List of Stations\n";
    vector<const Station*>::const_iterator it;
    for(it = Railways::sStations.begin(); it != Railways::sStations.end(); it++)
        os << *(*it) << endl;
    os << "\nPairwise Distances\n";

    map<pair<string, string>, int>::const_iterator iter;
    for(iter = Railways::sDistStations.begin(); iter != Railways::sDistStations.end(); iter++) {
        string s1 = (iter -> first).first;
        string s2 = (iter -> first).second;
        os << s1 << " - " << s2 << " = " << iter -> second << " km\n";
    }
    return os;
}
