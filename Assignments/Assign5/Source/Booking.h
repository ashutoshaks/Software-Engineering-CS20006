/*
    CS20006 Assignment 5
    Booking.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Header File for class Booking

#ifndef __BOOKING_H // Control inclusion of header files
#define __BOOKING_H

// Project Headers
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Passenger.h"
#include "Concession.h"
#include "Exceptions.h"

// C++ Headers
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
class BookingType;

class Booking {
private:
    struct GeneralType {};
    struct LadiesType {};
    struct SeniorCitizenType {};
    struct TatkalType {};
    struct PremiumTatkalType {};

protected:
    const Station& fromStation_;
    const Station& toStation_;
    const Date dateOfBooking_;
    const BookingClass& bookingClass_;
    const BookingCategory& bookingCategory_;
    const Passenger& passenger_;
    const Date dateOfReservation_;
    bool bookingStatus_; // Booking status for the booking
    string bookingMessage_;
    int fare_;
    const int PNR_;
    static int sBookingPNRSerial;
    static const double sBaseFarePerKM;

    Booking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                    const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation, bool bookingStatus = true,
                    const string& bookingMessage = "BOOKING SUCCEEDED"): 
                    fromStation_(fromStation), toStation_(toStation), dateOfBooking_(dateOfBooking), bookingClass_(bookingClass),
                    bookingCategory_(bookingCategory), passenger_(passenger), dateOfReservation_(dateOfReservation), 
                    bookingStatus_(bookingStatus), bookingMessage_(bookingMessage), PNR_(Booking::sBookingPNRSerial++)
    {
        Booking::sBookings.push_back(this); // Add to the list of Bookings sBookings
    }    virtual int computeFare() const = 0;

public:
    static vector<Booking*> sBookings;

    // add functions
    virtual ~Booking() {}
    static Booking* ReserveBooking(const string&, const string&, const string&, const BookingClass&, const BookingCategory&, 
                                const Passenger*, bool = true, const string& = "BOOKING SUCCEEDED");

    friend ostream& operator<<(ostream&, const Booking&);

    static void UnitTestBooking();

    typedef BookingType<GeneralType> GeneralBooking;
    typedef BookingType<LadiesType> LadiesBooking;
    typedef BookingType<SeniorCitizenType> SeniorCitizenBooking;
    typedef BookingType<TatkalType> TaktalBooking;
    typedef BookingType<PremiumTatkalType> PremiumTatkalBooking;
};

template <typename T>
class BookingType : public Booking {
private:
    virtual int computeFare() const;

public:
    BookingType(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation) : 
                Booking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation) {}
};

template <typename T>
class DivyaangBookingType;

class DivyaangBooking : public Booking {
private:
    struct BlindType {};
    struct OrthoHandicappedType {};
    struct CancerType {};
    struct TBType {};

protected:
    DivyaangBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation) : 
                Booking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation) {}

    virtual int computeFare() const = 0;

public:
    typedef DivyaangBookingType<BlindType> BlindBooking;
    typedef DivyaangBookingType<OrthoHandicappedType> OrthoHandicappedBooking;
    typedef DivyaangBookingType<CancerType> CancerBooking;
    typedef DivyaangBookingType<TBType> TBBooking;
};

template <typename T>
class DivyaangBookingType : public DivyaangBooking {
private:
    virtual int computeFare() const;

public:
    DivyaangBookingType(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation) : 
                DivyaangBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation) {}
};

#endif // __BOOKING_H