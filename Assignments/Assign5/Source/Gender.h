/*
    CS20006 Assignment 5
    Gender.h
    @author Ashutosh Kumar Singh (19CS30008)
*/

#ifndef __GENDER_H
#define __GENDER_H

#include <iostream>
#include <string>
using namespace std;

// Forward declaration of templatized class
template <typename T>
class GenderTypes; // Generic Gender type to generate specific genders

// Generic gender type
class Gender { // Abstract Base Class
    const string& name_; // Name of the Gender

    struct MaleType {};
    struct FemaleType {};

protected:
    Gender(const string& name) : name_(name) {}
    
    virtual ~Gender() {}

public:
    const string& GetName() const {
        return name_;
    }

    virtual const string GetTitle() const = 0; // Salutation specific to gender
    static bool IsMale(const Gender&); // Checking and matching gender

    friend ostream& operator<<(ostream&, const Gender&);

    static void UnitTestGender();
    
    // Enumerated types - the target sub-types
    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
};

// Specific gender types
template <typename T>
class GenderTypes : public Gender {
    static const string sName; // Respective name of the gender
    static const string sSalutation; // Respective salutation for the gender

    GenderTypes(const string &name = GenderTypes<T>::sName) : Gender(name) {}

    ~GenderTypes() {}

public:
    // Singleton object - placeholder for the respective type
    static const GenderTypes<T>& Type() {
        static const GenderTypes<T> theObject;
        return theObject;
    }

    const string GetTitle() const { // Dynamic dispatch
        return GenderTypes<T>::sSalutation; // Salutation parametrized by static
    }
};

inline bool Gender::IsMale(const Gender& g) {
    return &g == &Gender::Male::Type();
}

#endif // __GENDER_H