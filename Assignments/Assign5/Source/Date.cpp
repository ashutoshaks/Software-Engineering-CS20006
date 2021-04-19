/*
    CS20006 Assignment 5
    Date.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Date

// Including project header files
#include "Date.h"

// Initializing the static variables
const vector<string> Date::sMonthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const vector<string> Date::sDayNames = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

Duration::Duration(int days, int months, int years) : days_(days), months_(months), years_(years) {}

int Duration::GetDays() const {
    return days_;
}

int Duration::GetMonths() const {
    return months_;
}

int Duration::GetYears() const {
    return years_;
}

bool operator<(const Duration& d1, const Duration& d2) {
    if(d1.years_ < d2.years_)
        return true;
    else if(d1.years_ == d2.years_) {
        if(d1.months_ < d2.months_)
            return true;
        else if(d1.months_ == d2.months_) {
            if(d1.days_ < d2.days_)
                return true;
        }
    }
    return false;
}

Date::Date(int d, int m, int y) : date_(d), month_(static_cast<Month>(m)), year_(y) {}

Date::Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_) {}

const Date* Date::CreateDate(const string& date) {
    size_t len = date.length();
    size_t i = date.find_first_of("/");
    if(i < 1 || i > len - 2)
        throw Invalid_Date("Date is invalid for : " + date);

    int day = atoi((date.substr(0, i)).c_str());
    if(day < 1)
        throw Invalid_Date("Date is invalid for : " + date);

    size_t j = date.find_first_of("/", i + 1);
    if(j < 1 || j > len - 2)
        throw Invalid_Date("Date is invalid for : " + date);

    int mon = atoi((date.substr(i + 1, j - i)).c_str());
    if(mon < 1 || mon > 12)
        throw Invalid_Date("Date is invalid for : " + date);

    Month month = static_cast<Month>(mon);
    int year = atoi((date.substr(j + 1, date.length() - j)).c_str());

    if(year < 1900 || year > 2099)
        throw Date_Out_Of_Range("Year " + to_string(year) + " is not in the valid range");

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if(month == 2) {
            if(day > 29)
                throw Invalid_Date("Date is invalid for : " + date);
        }
    }
    else {
        if(month == 2) {
            if(day > 28)
                throw Invalid_Date("Date is invalid for : " + date);
        }
    }

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if(day > 31)
            throw Invalid_Date("Date is invalid for : " + date);
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11 ) {
        if(day > 30)
            throw Invalid_Date("Date is invalid for : " + date);
    }

    return new Date(day, month, year);
}

Date::Day Date::day() const {
    // Get the day of the week using the ctime library
    struct tm curr_date = {0, 0, 0, date_, month_ - 1, year_ - 1900};
    time_t rawtime = mktime(&curr_date);
    return static_cast<Date::Day>(localtime(&rawtime) -> tm_wday);
}

const Date* Date::Today() {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    return new Date(ltm -> tm_mday, 1 + ltm -> tm_mon , 1900 + ltm -> tm_year);
}

Duration operator-(const Date& to, const Date& from) {
    int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
    int daysInc = 0;
    if(to.date_ - from.date_ < 0) {
        int mon = to.month_ - 2; // -1 from zero, -1 previous month.
        if(mon < 0)
            mon = 11; // Previous month is December.
        daysInc = increment[mon];
        if((mon == 1) && ((to.year_ % 4 == 0 && to.year_ % 100 != 0) || (to.year_ % 400 == 0)))
            daysInc++; // Increment days for leap year.
    }

    int total1 = from.year_ * 360 + from.month_ * 30 + from.date_;
    int total2 = to.year_ * 360 + to.month_ * 30 + to.date_;
    int diff = total2 - total1;
    int years = diff / 360;
    int months = (diff - years * 360) / 30;
    int days = diff - years * 360 - months * 30 + daysInc;

    // Extra calculation when we can pass one month instead of 30 days.
    if(from.date_ == 1 && to.date_ == 31) {
        months--;
        days = 30;
    }
    return Duration(days, months, years);
}

bool operator>(const Date& d1, const Date& d2) {
    if(d1.year_ > d2.year_)
        return true;
    else if(d1.year_ == d2.year_) {
        if(d1.month_ > d2.month_)
            return true;
        else if(d1.month_ == d2.month_) {
            if(d1.date_ > d2.date_)
                return true;
        }
    }
    return false;
}

bool operator==(const Date& d1, const Date& d2) {
    return ((d1.date_ == d2.date_) && (d1.month_ == d2.month_) && (d1.year_ == d2.year_));
}

ostream& operator<<(ostream& os, const Date& d) {
    os << Date::sDayNames[d.day()] << ", " << d.date_ << "/" << Date::sMonthNames[d.month_ - 1] << "/" << d.year_;
    return os;
}

ostream& operator<<(ostream& os, const Duration& d) {
    os << d.years_ << " years, " << d.months_ << " months, " << d.days_ << " days";
    return os;
}
