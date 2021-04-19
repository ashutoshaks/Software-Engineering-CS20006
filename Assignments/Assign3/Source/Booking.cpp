/*
    CS20006 Assignment 3
    Booking.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Booking

// Including project header files
#include "Booking.h"

// Initializing the static variables
int Booking::sBookingPNRSerial = 1;
vector<Booking*> Booking::sBookings;

Booking::Booking(const Station& fromStation, const Station& toStation, const Date& date, const BookingClasses& bookingClass, bool bookingStatus, const string& bookingMessage, Passenger* passenger):
fromStation_(fromStation), toStation_(toStation), date_(date), bookingClass_(bookingClass), bookingStatus_(bookingStatus), bookingMessage_(bookingMessage), passenger_(passenger), PNR_(Booking::sBookingPNRSerial++)
{
    fare_ = this -> ComputeFare();
    Booking::sBookings.push_back(this); // Add to the list of Bookings sBookings
}

Booking::~Booking()
{}

int Booking::ComputeFare()
{
    // Implementation of the fare computation logic
    double baseFare = Booking::sBaseFarePerKM * Railways::Type().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor(); // Get loaded fare
    double finalFare = loadedFare;
    if(bookingClass_.IsAC())
        finalFare += Booking::sACSurcharge; // Add AC Surcharge
    if(bookingClass_.IsLuxury())
        finalFare += finalFare * (Booking::sLuxuryTaxPercent / 100.0); // Add ;uxury tax
    return static_cast<int>(round(finalFare)); // Round off the final fare to the nearest integer
}

ostream& operator<<(ostream& os, const Booking& booking)
{
    os << booking.bookingMessage_ << endl;
    os << "PNR Number = " << booking.PNR_ << endl;
    os << "From Station = " << booking.fromStation_.GetName() << endl;
    os << "To Station = " << booking.toStation_.GetName() << endl;
    os << "Travel Date = " << booking.date_ << endl;
    os << booking.bookingClass_ ;
    os << "Fare = " << booking.fare_ << endl;
    return os;
}

