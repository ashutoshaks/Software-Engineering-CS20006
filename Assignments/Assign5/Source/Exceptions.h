/*
    CS20006 Assignment 5
    Exceptions.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Exceptions : public exception {
protected:
    const string message_;
public:
    Exceptions(const string&);
    virtual const char* what() const throw();
};



class Bad_Date : public Exceptions {
public:
    Bad_Date(const string&);
};

class Invalid_Date : public Bad_Date {
public:
    Invalid_Date(const string&);
};

class Date_Out_Of_Range : public Bad_Date {
public:
    Date_Out_Of_Range(const string&);
};



class Bad_Station : public Exceptions {
public:
    Bad_Station(const string&);
};



class Bad_Railways : public Exceptions {
public:
    Bad_Railways(const string&);
};

class Duplicate_Station: public Bad_Railways {
public:
    Duplicate_Station(const string&);
};

class Duplicate_Pair: public Bad_Railways {
public:
    Duplicate_Pair(const string&);
};



class Bad_Passenger : public Exceptions {
public:
    Bad_Passenger(const string&);
};

class Invalid_Name : public Bad_Passenger {
public:
    Invalid_Name(const string&);
};

class Wrong_DOB : public Bad_Passenger {
public:
    Wrong_DOB(const string&);
};

class Wrong_Aadhaar : public Bad_Passenger {
public:
    Wrong_Aadhaar(const string&);
};

class Wrong_Mobile : public Bad_Passenger {
public:
    Wrong_Mobile(const string&);
};



class Bad_Booking : public Exceptions {
public:
    Bad_Booking(const string&);
};

class Same_Stations : public Bad_Booking {
public:
    Same_Stations(const string&);
};

class Invalid_Booking_Date : public Bad_Booking {
public:
    Invalid_Booking_Date(const string&);
};

#endif // __EXCEPTIONS_H