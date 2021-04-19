/*
    CS20006 Assignment 5
    Name.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "Name.h"

Name::Name(const string& firstName, const string& middleName, const string& lastName) : firstName_(firstName), middleName_(middleName), lastName_(lastName)
{}

const Name* Name::CreateName(const string& firstName, const string& middleName, const string& lastName) {
    if(firstName == "" && middleName == "" && lastName == "")
        throw Invalid_Name("Name cannot be completely empty");
    else if(firstName == "" && lastName == "")
        throw Invalid_Name("At least one of first name or last name should be present");

    return new Name(firstName, middleName, lastName);
}

ostream& operator<<(ostream& os, const Name& name) {
    os << name.firstName_ << (name.firstName_ != "" ? " " : "") << name.middleName_ << (name.middleName_ != "" ? " " : "") << name.lastName_;
    return os;
}