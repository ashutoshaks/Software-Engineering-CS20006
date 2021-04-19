/*
    CS20006 Assignment 5
    Passenger.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for class Passenger

#ifndef __PASSESNGER_H // Control inclusion of header files
#define __PASSESNGER_H

// Project Headers
#include "Date.h"
#include "Gender.h"
#include "Name.h"
#include "Exceptions.h"

// C++ Headers
#include <iostream>
#include <string>
using namespace std;

class Divyaang;

// Class declaration for the class Passenger
class Passenger
{
protected:
    const Name& name_;
    const Date& dateOfBirth_;
    const Gender& gender_;
    const string aadhaar_;
    const string mobile_;
    const Divyaang* disabilityType_;
    const string disabilityID_;

public:
    Passenger(const Name&, const Date&, const Gender&, const string&, const string& = "", const Divyaang* = NULL, const string& = "");
    ~Passenger() {}
    static const Passenger* CreatePassenger(const string&, const string&, const string&, const string&, const Gender&, const string&, const string& = "", const Divyaang* = NULL, const string& = "");
    const Date GetDateOfBirth() const;
    const Gender& GetGender() const;
    const Divyaang* GetDisability() const;

    friend ostream& operator<<(ostream&, const Passenger&);

    static void UnitTestPassenger();
};

#endif