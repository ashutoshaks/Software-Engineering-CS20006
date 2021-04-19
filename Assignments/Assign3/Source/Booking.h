/*
    CS20006 Assignment 3
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
#include "BookingClasses.h"
#include "Passenger.h"

// C++ Headers
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Class Declaration for the Booking class
class Booking
{
private:
    const Station fromStation_; // Station from which booking is done
    const Station toStation_; // Station to which booking is done
    const Date date_; // Date of travel
    const BookingClasses& bookingClass_; // Booking Class of travel
    const Passenger* passenger_; // Passenger details (nullable default for now)
    bool bookingStatus_; // Booking status for the booking
    string bookingMessage_; // Booking message received after booking
    int fare_; // Fare incurred for the booking
    const int PNR_; // PNR for the booking
    static int sBookingPNRSerial; // Static variable to allocate PNRs serially starting from 1

    Booking(const Booking&); // Blocked copy constructor
    Booking& operator=(const Booking&); // Blocked copy assignment operator

public:
    static const double sBaseFarePerKM; // Base fare per km
    static const int sACSurcharge; // AC Surcharge
    static const int sLuxuryTaxPercent; // Luxury Tax Percentage 
    static vector<Booking*> sBookings; // List of all bookings

    Booking(const Station&, const Station&, const Date&, const BookingClasses&, bool = true, const string& = "BOOKING SUCCEEDED", Passenger* = NULL); // Constructor
    virtual ~Booking(); // Destructor
    virtual int ComputeFare(); // Function to compute the fare
    friend ostream& operator<<(ostream&, const Booking&); // Output streaming operator
    static void UnitTestBooking(); // Static function for unit testing
};

#endif // __BOOKING_H