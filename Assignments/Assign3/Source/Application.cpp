/*
    CS20006 Assignment 3
    Application.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

// Application Test File for the entire project

// Including project header files
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"

// Initializing static constants
const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.50;

const double Booking::sBaseFarePerKM = 0.5;
const int Booking::sACSurcharge = 50;
const int Booking::sLuxuryTaxPercent = 25;

// Test application for booking
void BookingApplication() 
{   
    // Initializing the singleton object IndianRailways
    const Railways& IndianRailways = Railways::Type();

    // The vector travelFrom stores the Stations from where the Bookings are done
    // The vector travelTo stores the Stations upto where the Bookings are done
    vector<Station> travelFrom, travelTo;

    // The vector travelDates stores the Dates of travel
    vector<Date> travelDates;

    // THe vector distances stores the distances between the from and to Stations
    vector<int> distances;

    travelFrom.push_back(Station("Delhi")); // Create Station objects
    travelTo.push_back(Station("Mumbai"));
    travelDates.push_back(Date(20, 3, 2021)); // Create Date objects
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back())); // Get the distance between the Stations
    // Booking for ACFirstClass
    Booking b1(travelFrom.back(), travelTo.back(), travelDates.back(), ACFirstClass::Type());

    travelFrom.push_back(Station("Chennai"));
    travelTo.push_back(Station("Bangalore"));
    travelDates.push_back(Date(25, 3, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for AC2Tier
    Booking b2(travelFrom.back(), travelTo.back(), travelDates.back(), AC2Tier::Type());

    travelFrom.push_back(Station("Kolkata"));
    travelTo.push_back(Station("Mumbai"));
    travelDates.push_back(Date(10, 4, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for FirstClass
    Booking b3(travelFrom.back(), travelTo.back(), travelDates.back(), FirstClass::Type());

    travelFrom.push_back(Station("Kolkata"));
    travelTo.push_back(Station("Delhi"));
    travelDates.push_back(Date(15, 4, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for AC3Tier
    Booking b4(travelFrom.back(), travelTo.back(), travelDates.back(), AC3Tier::Type());

    travelFrom.push_back(Station("Bangalore"));
    travelTo.push_back(Station("Mumbai"));
    travelDates.push_back(Date(25, 4, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for ACChairCar
    Booking b5(travelFrom.back(), travelTo.back(), travelDates.back(), ACChairCar::Type());

    travelFrom.push_back(Station("Chennai"));
    travelTo.push_back(Station("Delhi"));
    travelDates.push_back(Date(1, 5, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for Sleeper
    Booking b6(travelFrom.back(), travelTo.back(), travelDates.back(), Sleeper::Type());

    travelFrom.push_back(Station("Bangalore"));
    travelTo.push_back(Station("Kolkata"));
    travelDates.push_back(Date(10, 5, 2021));
    distances.push_back(IndianRailways.GetDistance(travelFrom.back(), travelTo.back()));
    // Booking for SecondSitting
    Booking b7(travelFrom.back(), travelTo.back(), travelDates.back(), SecondSitting::Type());

    int n = (int)travelFrom.size(), i;

    // Iterate over the vectors to print the various details
    for(i = 0; i < n; i++)
    {
        cout << "Index - " << i + 1 << endl;
        cout << travelFrom[i] << " - " << travelTo[i] << " - " << distances[i] << " km\n\n";
        cout << *(Booking::sBookings[i]) << endl << endl;
    }

}
    
int main() 
{
    BookingApplication();

    return 0;
}