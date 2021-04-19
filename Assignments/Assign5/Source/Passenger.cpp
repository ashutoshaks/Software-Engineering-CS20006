/*
    CS20006 Assignment 5
    Passenger.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

#include "Passenger.h"
#include "BookingCategory.h"

Passenger::Passenger(const Name& name, const Date& dob, const Gender& gender, const string& aadhaar, const string& mobile, const Divyaang* disabilityType, const string& disabilityID):
            name_(name), dateOfBirth_(dob), gender_(gender), aadhaar_(aadhaar), mobile_(mobile), disabilityType_(disabilityType), disabilityID_(disabilityID)
{}

const Passenger* Passenger::CreatePassenger(const string& firstName, const string& middleName, const string& lastName, const string& dob, const Gender& gender, const string& aadhaar, const string& mobile, const Divyaang* disabilityType, const string& disabilityID)
{
    const Name* name = NULL;
    const Date* dateOfBirth = NULL;
    bool flag = 0;
    try {
        name = Name::CreateName(firstName, middleName, lastName);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    try {
        dateOfBirth = Date::CreateDate(dob);
    } catch(Bad_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    try {
        if(dateOfBirth != NULL && *dateOfBirth > *Date::Today())
            throw Bad_Passenger("Date of Birth cannot be in the future");
    } catch(Bad_Passenger& e) {
        cout << e.what() << endl;
        flag = 1;
    }
    
    try {
        if(aadhaar.length() != 12)
            throw Wrong_Aadhaar("Aadhaar No. is not of length 12 : " + aadhaar);
        for(size_t i = 0; i < 12; i++) {
            if(!(aadhaar[i] >= '0' && aadhaar[i] <= '9'))
            throw Wrong_Aadhaar("Non-digits are not allowed in Aadhaar no. : " + aadhaar);
        }
    } catch (Wrong_Aadhaar& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    if(mobile != "") {
        try {
            if(mobile.length() != 10)
                throw Wrong_Mobile("Mobile No. is not of length 10 : " + mobile);
            for(size_t i = 0; i < 10; i++) {
                if(!(mobile[i] >= '0' && mobile[i] <= '9'))
                throw Wrong_Aadhaar("Non-digits are not allowed in Mobile no. : " + mobile);
            }
        } catch (Wrong_Mobile& e) {
            cout << e.what() << endl;
            flag = 1;
        }
    }
    
    if(flag == 1)
        throw Bad_Passenger("Passenger information is not valid");
    
    return new Passenger(*name, *dateOfBirth, gender, aadhaar, mobile, disabilityType, disabilityID);
}

const Date Passenger::GetDateOfBirth() const {
    return dateOfBirth_;
}

const Gender& Passenger::GetGender() const{
    return gender_;
}
const Divyaang* Passenger::GetDisability() const {
    return disabilityType_;
}

ostream& operator<<(ostream& os, const Passenger& p) {
    os << "Name: " << p.name_ << endl;
    os << "Date Of Birth: " << p.dateOfBirth_ << endl;
    os << "Gender: " << p.gender_ << endl;
    os << "Aadhaar: " << p.aadhaar_ << endl;
    if(p.mobile_ != "")
        os << "Mobile: " << p.mobile_ << endl;
    if(p.disabilityType_ != NULL) 
        os << "Disability Type: " << p.disabilityType_ -> GetName().substr(11) << endl;
    if(p.disabilityID_ != "")
        os << "Disability ID: " << p.disabilityID_ << endl;
    return os;
}