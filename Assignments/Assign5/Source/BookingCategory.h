/*
    CS20006 Assignment 5
    BookingCategory.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

#ifndef __BOOKINGCATEGORY_H
#define __BOOKINGCATEGORY_H

#include "Passenger.h"

#include <iostream>
#include <string>
using namespace std;

class Station;
class Date;
class BookingClass;
class Passenger;
class Booking;
template <typename T>
class BookingType;
class DivyaangBooking;
template <typename T>
class DivyaangBookingType;
template <typename T>
class BookingCategoryType;

class BookingCategory {
private:
    struct GeneralType {};
    struct LadiesType {};
    struct SeniorCitizenType {};
    struct TatkalType {};
    struct PremiumTatkalType {};

protected:
    BookingCategory() {}
    virtual ~BookingCategory() {}

public:
    virtual const string GetName() const = 0;
    virtual const bool IsEligible(const Passenger&) const = 0;
    virtual Booking* CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation, bool bookingStatus, 
                            const string& bookingMessage) const = 0;

    friend ostream& operator<<(ostream&, const BookingCategory&);

    static void UnitTestBookingCategory();

    typedef BookingCategoryType<GeneralType> General;
    typedef BookingCategoryType<LadiesType> Ladies;
    typedef BookingCategoryType<SeniorCitizenType> SeniorCitizen;
    typedef BookingCategoryType<TatkalType> Tatkal;
    typedef BookingCategoryType<PremiumTatkalType> PremiumTatkal;
};

template <typename T>
class BookingCategoryType : public BookingCategory {
private:
    static const string sName;

    BookingCategoryType() {}
    ~BookingCategoryType() {}

public:
    static const BookingCategoryType<T>& Type() {
        static const BookingCategoryType<T> theObject;
        return theObject;
    }

    const string GetName() const {
        return BookingCategoryType<T>::sName;
    }

    virtual const bool IsEligible(const Passenger&) const;

    Booking* CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus = true, const string& bookingMessage = "BOOKING SUCCEEDED") const;
};

template <typename T>
class DivyaangType;

class Divyaang : public BookingCategory {
private: 
    struct BlindType {};
    struct OrthoHandicappedType {};
    struct CancerType {};
    struct TBType {};

protected:
    Divyaang() {}
    ~Divyaang() {}

public:
    virtual const string GetName() const = 0;

    typedef DivyaangType<BlindType> Blind;
    typedef DivyaangType<OrthoHandicappedType> OrthoHandicapped;
    typedef DivyaangType<CancerType> Cancer;
    typedef DivyaangType<TBType> TB;

    virtual const bool IsEligible(const Passenger&) const = 0;

    virtual Booking* CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus = true, const string& bookingMessage = "BOOKING SUCCEEDED") const = 0;
};

template <typename T>
class DivyaangType : public Divyaang {
private:
    static const string sName;

    DivyaangType() {}
    ~DivyaangType() {}

public:
    static const DivyaangType<T>& Type() {
        static const DivyaangType<T> theObject;
        return theObject;
    }

    const string GetName() const {
        return DivyaangType<T>::sName;
    }

    virtual const bool IsEligible(const Passenger&) const;

    Booking* CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus = true, const string& bookingMessage = "BOOKING SUCCEEDED") const;
};


# endif // __BOOKINGCATEGORY_H
