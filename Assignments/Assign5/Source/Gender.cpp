/*
    CS20006 Assignment 5
    Gender.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "Gender.h"

using namespace std;

// Names defined as static constants
template<> const string Gender::Male::sName = "Male";
template<> const string Gender::Female::sName = "Female";

// Salutations defined as static constants
template<> const string Gender::Male::sSalutation = "Mr.";
template<> const string Gender::Female::sSalutation = "Ms.";

ostream& operator<<(ostream& os, const Gender& g) {
    os << g.GetName();
    return os;
}