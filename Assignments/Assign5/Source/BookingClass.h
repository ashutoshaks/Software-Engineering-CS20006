/*
    CS20006 Assignment 5
    BookingClass.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for the hierarchy of booking classes

#ifndef __BOOKINGCLASS_H // Control inclusion of header files
#define __BOOKINGCLASS_H

// C++ Headers
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BookingClassType;

class BookingClass {
private:
    struct ACFirstClassType {};
    struct ExecutiveChairCarType {};
    struct AC2TierType {};
    struct FirstClassType {};
    struct AC3TierType {};
    struct ACChairCarType {};
    struct SleeperType {};
    struct SecondSitingType {};

protected:
    BookingClass() {}
    virtual ~BookingClass() {}

public:
    virtual const string GetName() const = 0;
    virtual const double GetLoadFactor() const = 0;
    virtual const bool IsSitting() const = 0;
    virtual const bool IsAC() const = 0;
    virtual const int GetNumberOfTiers() const = 0;
    virtual const bool IsLuxury() const = 0;
    virtual const double GetReservationCharge() const = 0;
    virtual const double GetTatkalLoadFactor() const = 0;
    virtual const double GetMinTatkalCharge() const = 0;
    virtual const double GetMaxTatkalCharge() const = 0;
    virtual const int GetMinTatkalDistance() const = 0;

    friend ostream& operator<<(ostream& os, const BookingClass&);

    typedef BookingClassType<ACFirstClassType> ACFirstClass;
    typedef BookingClassType<ExecutiveChairCarType> ExecutiveChairCar;
    typedef BookingClassType<AC2TierType> AC2Tier;
    typedef BookingClassType<FirstClassType> FirstClass;
    typedef BookingClassType<AC3TierType> AC3Tier;
    typedef BookingClassType<ACChairCarType> ACChairCar;
    typedef BookingClassType<SleeperType> Sleeper;
    typedef BookingClassType<SecondSitingType> SecondSitting;
};

template <typename T>
class BookingClassType : public BookingClass {
private:
    static const string sName;
    static const bool sIsSitting;
    static const bool sIsAC;
    static const int sNumberOfTiers;
    static const double sLoadFactor;
    static const bool sIsLuxury;
    static const double sReservationCharge;
    static const double sTatkalLoadFactor;
    static const double sMinTatkalCharge;
    static const double sMaxTatkalCharge;
    static const int sMinTatkalDistance;

    BookingClassType() {}
    ~BookingClassType() {}

public:
    static const BookingClassType<T>& Type() {
        static const BookingClassType<T> theObject;
        return theObject;
    }

    const string GetName() const {
        return BookingClassType<T>::sName;
    }

    const double GetLoadFactor() const {
        return BookingClassType<T>::sLoadFactor;
    }

    const bool IsSitting() const {
        return BookingClassType<T>::sIsSitting;
    }

    const bool IsAC() const {
        return BookingClassType<T>::sIsAC;
    }

    const int GetNumberOfTiers() const {
        return BookingClassType<T>::sNumberOfTiers;
    }

    const bool IsLuxury() const {
        return BookingClassType<T>::sIsLuxury;
    }

    const double GetReservationCharge() const {
        return BookingClassType<T>::sReservationCharge;
    }

    const double GetTatkalLoadFactor() const {
        return BookingClassType<T>::sTatkalLoadFactor;
    }

    const double GetMinTatkalCharge() const {
        return BookingClassType<T>::sMinTatkalCharge;
    }

    const double GetMaxTatkalCharge() const {
        return BookingClassType<T>::sMaxTatkalCharge;
    }

    const int GetMinTatkalDistance() const {
        return BookingClassType<T>::sMinTatkalDistance;
    }

    static void UnitTest(); 
};


#endif // __BOOKINGCLASS_H