/*
    CS20006 Assignment 5
    Date.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for class Date

#ifndef __DATE_H // Control inclusion of header files
#define __DATE_H

#include "Exceptions.h"

// C++ Headers
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Duration;

struct DateDiff;

// Class Declaration for the Date class
class Date {
private:
    // Enum declarations
    enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

    static const vector<string> sMonthNames; // List of month names
    static const vector<string> sDayNames; // List of day names
    const int date_; // date variable
    const Month month_; // month variable
    const int year_; // year variable

    Date& operator=(const Date&); // Blocked copy assignment operator
    
public:
    Date(int, int, int); // Constructor
    Date(const Date&); // Copy Constructor
    ~Date() {} // Destructor
    Day day() const; // Function to get day from date
    static const Date* CreateDate(const string&);
    static const Date* Today();
    friend Duration operator-(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend ostream& operator<<(ostream&, const Date&); // Output Streaming Operator
    static void UnitTestDate(); // Static function for unit testing
};

class Duration {
private:
    int days_;
    int months_;
    int years_;

public:
    Duration(int, int, int);
    ~Duration() {}

    int GetDays() const;
    int GetMonths() const;
    int GetYears() const;

    friend bool operator<(const Duration&, const Duration&);
    friend ostream& operator<<(ostream&, const Duration&);
};

#endif // __DATE_H