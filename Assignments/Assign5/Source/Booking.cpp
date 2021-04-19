/*
    CS20006 Assignment 5
    Booking.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Source File for class Booking

// Including project header files
#include "Booking.h"

// Initializing the static variables
int Booking::sBookingPNRSerial = 1;
// const double Booking::sBaseFarePerKM = 0.50; // To be put in application
vector<Booking*> Booking::sBookings;


Booking* Booking::ReserveBooking(const string& fromStationName, const string& toStationName, const string& bookingDate, const BookingClass& bookingClass, 
                        const BookingCategory& bookingCategory, const Passenger* passenger, bool bookingStatus, const string& bookingMessage)
{
    const Station* fromStation = NULL;
    const Station* toStation = NULL;
    const Date* dateOfBooking = NULL;
    bool flag = 0;
    if(passenger == NULL)
        flag = 1;
    
    try {
        fromStation = Railways::IndianRailways().GetStation(fromStationName);
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    try {
        toStation = Railways::IndianRailways().GetStation(toStationName);
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    try {
        if(fromStation == toStation && fromStation != NULL && toStation != NULL)
            throw Same_Stations("From Station and To Station are same, which is not possible");
    } catch (Same_Stations& e) {
        cout << e.what() << endl; 
        flag = 1;
    }

    try {
        dateOfBooking = Date::CreateDate(bookingDate);
    } catch(Bad_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    if(dateOfBooking == NULL)
        throw Bad_Booking("Invalid Booking Information");

    const Date* dateOfReservation = Date::Today();

    try {
        if(*dateOfBooking == *dateOfReservation)
            throw Invalid_Booking_Date("Same day booking is not allowed");
    } catch(Invalid_Booking_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    try {
        if(!(*dateOfBooking > *dateOfReservation))
            throw Invalid_Booking_Date("Date Of Booking should be later than Date of Reservation");
        if(!((*dateOfBooking) - *dateOfReservation < Duration(1, 0, 1)))
            throw Invalid_Booking_Date("Date Of Booking should be within one year of Date of Reservation");
    } catch (Invalid_Booking_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    if(passenger != NULL && dateOfBooking != NULL) {
        try {
            if(!bookingCategory.IsEligible(*passenger))
                throw Bad_Booking("Not eligible for the given Booking Category : " + bookingCategory.GetName());
            if((&bookingCategory == &BookingCategory::Tatkal::Type()) || (&bookingCategory == &BookingCategory::PremiumTatkal::Type())) {
                if(!((*dateOfBooking) - *dateOfReservation < Duration(2, 0, 0)))
                    throw Bad_Booking("For Tatkal or Premium Tatkal, booking should be done 1 day before travel");
            }
        } catch(Bad_Booking& e) {
            cout << e.what() << endl;
            flag = 1;
        }
    }

    if(flag == 1)
        throw Bad_Booking("Could not create Booking");
    Booking* booking = bookingCategory.CreateBooking(*fromStation, *toStation, *dateOfBooking, bookingClass, bookingCategory, *passenger, *dateOfReservation, bookingStatus, bookingMessage);
    booking -> fare_ = booking -> computeFare();
    return booking;
}


template<>
int Booking::GeneralBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    // cout << baseFare << endl << loadedFare << endl << finalFare << endl;
    return static_cast<int>(finalFare + 0.50);
}

template<>
int Booking::LadiesBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - LadiesConcession::Type().GetFactor());
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::SeniorCitizenBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - SeniorCitizenConcession::Type().GetFactor(passenger_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::TaktalBooking::computeFare() const {
    int dist = Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double baseFare = Booking::sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor();
    if(dist < bookingClass_.GetMinTatkalDistance() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + tatkalFare + bookingClass_.GetReservationCharge();
    // cout << baseFare << endl << loadedFare << endl << finalFare << endl;
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::PremiumTatkalBooking::computeFare() const {
    int dist = Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double baseFare = Booking::sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor() * 2.00;
    if(dist < bookingClass_.GetMinTatkalDistance() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + (2.0 * tatkalFare) + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::BlindBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::OrthoHandicappedBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::CancerBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::TBBooking::computeFare() const {
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

ostream& operator<<(ostream& os, const Booking& booking) {
    os << booking.bookingMessage_ << endl;
    os << "PNR Number = " << booking.PNR_ << endl;
    os << "From Station = " << booking.fromStation_.GetName() << endl;
    os << "To Station = " << booking.toStation_.GetName() << endl;
    os << "Travel Date = " << booking.dateOfBooking_ << endl;
    os << booking.bookingClass_ ;
    os << "Booking Category = " << booking.bookingCategory_ << endl;
    os << "Passenger Information : \n" << booking.passenger_ << endl;
    os << "Reservation Date = " << booking.dateOfReservation_ << endl;
    os << "Fare = " << booking.fare_ << endl;
    return os;
}
