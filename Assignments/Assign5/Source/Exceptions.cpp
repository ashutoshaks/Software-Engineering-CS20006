/*
    CS20006 Assignment 5
    Exceptions.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "Exceptions.h"

Exceptions::Exceptions(const string& msg) : message_(msg) {}

const char* Exceptions::what() const throw() {
    return message_.c_str();
}

Bad_Date::Bad_Date(const string& msg) : Exceptions(msg) {}

Invalid_Date::Invalid_Date(const string& msg) : Bad_Date(msg) {}

Date_Out_Of_Range::Date_Out_Of_Range(const string& msg) : Bad_Date(msg) {}

Bad_Station::Bad_Station(const string& msg) : Exceptions(msg) {}

Bad_Railways::Bad_Railways(const string& msg) : Exceptions(msg) {}

Duplicate_Station::Duplicate_Station(const string& msg) : Bad_Railways(msg) {}

Duplicate_Pair::Duplicate_Pair(const string& msg) : Bad_Railways(msg) {}

Bad_Passenger::Bad_Passenger(const string& msg) : Exceptions(msg) {}

Invalid_Name::Invalid_Name(const string& msg) : Bad_Passenger(msg) {}

Wrong_DOB::Wrong_DOB(const string& msg) : Bad_Passenger(msg) {}

Wrong_Aadhaar::Wrong_Aadhaar(const string& msg) : Bad_Passenger(msg) {}

Wrong_Mobile::Wrong_Mobile(const string& msg) : Bad_Passenger(msg) {}

Bad_Booking::Bad_Booking(const string& msg) : Exceptions(msg) {}

Same_Stations::Same_Stations(const string& msg) :  Bad_Booking(msg) {}

Invalid_Booking_Date::Invalid_Booking_Date(const string& msg) : Bad_Booking(msg) {}
