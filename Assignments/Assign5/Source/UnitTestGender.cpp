/*
    CS20006 Assignment 5
    UnitTestGender.cpp
    @author Ashutosh Kumar Singh (19CS30008)
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Gender.cpp UnitTestGender.cpp -o test
    ./test
*/

// Unit Testing File for class Gender

// Including project header files
#include "Gender.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Gender::UnitTestGender() {
    // Testing the Male class
    const Gender::Male* firstPointer = &Gender::Male::Type();
    const Gender::Male* secondPointer = &Gender::Male::Type();
    assert(firstPointer == secondPointer);

    const Gender::Male& maleObj = Gender::Male::Type();

    assert("Male" == maleObj.GetName());

    assert("Mr." == maleObj.GetTitle());

    assert(true == Gender::IsMale(maleObj));

    stringstream out;
    out << maleObj;
    assert("Male" == out.str());

    cout << maleObj << endl;


    // Testing the Female class
    const Gender::Female* firstPointer1 = &Gender::Female::Type();
    const Gender::Female* secondPointer1 = &Gender::Female::Type();
    assert(firstPointer1 == secondPointer1);

    const Gender::Female& femaleObj = Gender::Female::Type();

    assert("Female" == femaleObj.GetName());

    assert("Ms." == femaleObj.GetTitle());

    assert(false == Gender::IsMale(femaleObj));

    out.str("");
    out << femaleObj;
    assert("Female" == out.str());

    cout << femaleObj << endl;

}

int main() {
    Gender::UnitTestGender();

    return 0;
}