/*
    CS20006 Assignment 5
    Name.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

#ifndef __NAME_H
#define __NAME_H

#include "Exceptions.h"

#include <iostream>
#include <string>
using namespace std;

class Name {
private:
    const string firstName_;
    const string middleName_;
    const string lastName_;

public:
    Name(const string&, const string&, const string&);
    ~Name() {}
    static const Name* CreateName(const string&, const string&, const string&);
    friend ostream& operator<<(ostream&, const Name&);
    static void UnitTestName();

    friend class Passenger;
};

#endif //__NAME_H