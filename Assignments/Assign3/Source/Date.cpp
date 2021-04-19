/*
    CS20006 Assignment 3
    Date.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Date

// Including project header files
#include "Date.h"

// Initializing the static variables
const vector<string> Date::sMonthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const vector<string> Date::sDayNames = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

Date::Date(int d, int m, int y) : date_(d), month_(static_cast<Month>(m)), year_(y)
{}

Date::Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_)
{}

Date::~Date()
{}

Date::Day Date::day() const
{
    // Get the day of the week using the ctime library
    struct tm curr_date = {0, 0, 0, date_, month_ - 1, year_ - 1900};
    time_t rawtime = mktime(&curr_date);
    return static_cast<Date::Day>(localtime(&rawtime) -> tm_wday);
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << Date::sDayNames[d.day()] << ", " << d.date_ << "/" << Date::sMonthNames[d.month_ - 1] << "/" << d.year_;
    return os;
}
