/*
    CS20006 Assignment 3
    Passenger.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for class Passenger

#ifndef __PASSESNGER_H // Control inclusion of header files
#define __PASSESNGER_H

// Project Headers
#include "Date.h"

// C++ Headers
#include <iostream>
using namespace std;

// Class declaration for the abstract class Passenger
// We do not make any object of this class in this project, but it is kept as an abstract class for future extension
class Passenger
{
protected:
    enum Gender {Male = 0, Female};
    const string name_;
    const string aadhaar_;
    const Date dateOfBirth_;
    const Gender gender_;
    string mobile_;
    const string category_;

public:
    virtual string GetCategory() = 0; // Pure virtual function to make the class abstract
};

#endif