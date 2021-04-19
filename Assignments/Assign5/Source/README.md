<!-- 
    CS20006 Assignment 5
    README.md
    @author Ashutosh Kumar Singh (19CS30008) 
-->

<!-- It is preferable to view the README file in a preview mode in some code editor for better readability. -->

# Railway Booking System

A rudimentary railway booking / reservation system designed by **Ashutosh Kumar Singh (19CS30008)** as an assignment in the Software Engineering Theory (CS20006) course.

This README file contains the details of the various header and source files used. It also has the instructions to compile and build the entire project and the instructions to compile and run the unit tests for each class. 

## Details of Various Header and Source Files

- **Station.h**  
This is the header file for the `Station` class and contains the declarations of all the data members, constructors and member functions of the `Station` class.

- **Station.cpp**  
This is the source file for the `Station` class. It contains the implementations of all the constructors and member functions declared in `Station.h`.

- **UnitTestStation.cpp**  
This file contains the function body for the unit testing function of the `Station` class.

- **Railways.h**  
This is the header file for the singleton `Railways` class and contains the declarations of all the data members and member functions of the `Railways` class.  

- **Railways.cpp**  
This is the source file for the `Railways` class. It contains the initializations of the static constants and the function bodies of the member functions in the `Railways` class.

- **UnitTestRailways.cpp**  
This file contains the function body for the unit testing function of the `Railways` class.

- **Date.h**  
This is the header file for the `Date` class and contains the declarations of all the data members, constructors and member functions of this class.

- **Date.cpp**  
This is the source file for the `Date` class. In this file, we first initialize the static constants of the `Date` class. Then we implement all the constructors and member functions declared in `Date.h`.

- **UnitTestDate.cpp**  
This file contains the function body for the unit testing function of the `Date` class.

- **Gender.h**  
Header file for the `Gender` class and its children - `Male` and `Female`.

- **Gender.cpp**  
Source file containing static constant initializations for the `Gender` class and hierarchy.

- **UnitTestGender.cpp**  
This file contains the function body for the unit testing function of the `Gender` class and its hierarchy.

- **Name.h**  
This is the header file for the `Name` class and contains the declarations of all the data members, constructors and member functions of this class.

- **Name.cpp**  
This is the source file for the `Name` class. Here we implement all the constructors and member functions declared in `Name.h`.

- **UnitTestName.cpp**  
This file contains the function body for the unit testing function of the `Name` class. 

- **Passenger.h**  
This is the header file for the `Passenger` class and contains the declarations of the data members of the `Passenger` class.

- **Passenger.cpp**  
This is the source file for the `Passenger` class and contains bodies of all the functions in this class.

- **UnitTestPassenger.cpp**  
File for unit testing the `Passenger` class.

- **BookingClass.h**  
This is the header file for the hierarchy of the various booking classes (categories). The root is the abstract base class `BookingClass`. We have 8 concrete child classes - `ACFirstClass`, `ExecutiveChairCar`, `AC2Tier`, `FirstClass`, `AC3Tier`, `ACChairCar` `Sleeper` and `SecondSitting`. All 8 of these are singleton classes.

- **BookingClass.cpp**  
This is the source file for the hierarchy of booking classes. It contains the implementations of all the constructors and member functions declared in `BookingClass.h`.

- **UnitTestBookingClass.cpp**  
This is the file for unit testing the `BookingClass` hierarchy.

- **BookingCategory.h**  
This is the header file for the hierarchy of `BookingCategory` and `Divyaang`.

- **BookingCategory.cpp**  
Source file corresponding to `BookingCategory.h`.

- **UnitTestBookingCategory.cpp**  
File for unit testing the `BookingCategory` and `Divyaang` hierarchies.

- **Concession.h**  
This is the header file for the `Concession` class and its hierarchy. They store the data about various applicable concessions.

- **Concession.cpp**  
Source file for the `Concession` hierarchy.

- **UnitTestConcession.cpp**  
This file contains the implementation to unit test the `Concession` hierarchy.

- **Exceptions.h**  
Header file for a custom made Exception hierarchy.

- **Exceptions.cpp**  
Source file corresponding to `Exceptions.h`.

- **Booking.h**  
This is the header file for the `Booking` class. It contains the declarations of all the data members, constructors and member functions of this class.

- **Booking.cpp**  
This is the source file for the `Booking` class. Here, we first initialize few of the static variables. Then we implement all the constructors and member functions declared in `Booking.h`.

- **UnitTestBooking.cpp**  
This file contains the function body for the unit testing function of the `Booking` class.

- **ApplicationTestPositive.cpp**  
Application testing file containing positive test scenarios.

- **ApplicationTestNegative.cpp**  
Application testing file containing negative test scenarios.

- **makefile**  
A simple makefile to compile and build the project.

## Compiler Used

We have used the GNU GCC compiler. The entire code is written in C++. The C++ standard followed is C++11. All libraries used are standard C++ libraries.

## Compilation and Build Instructions

To compile and build the project, ensure all the above listed files are in the same directory. Then navigate to that directory and run the following commands in the terminal:

```shell
$ make
$ ./rbs
```

Note that by default, the application file selected is `ApplicationTestPositive.cpp`. To change this, just pass the name of the application file which you want to use (without the .cpp extension) as an argument to the `make` command. For example, if you want to use the file `ApplicationTestNegative.cpp` as the application file, use the commands :

```shell
$ make APPFILE=ApplicationTestNegative
$ ./rbs
```

## Compilation and Build Instructions for Unit Testing the Individual Classes

- For unit testing the `Station` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestStation.cpp -o test
$ ./test
```

- For unit testing the `Railways` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestRailways.cpp -o test
$ ./test
```

- For unit testing the `Date` class, use the following commands :

```shell
$ g++ -std=c++11 Date.cpp Exceptions.cpp UnitTestDate.cpp -o test
$ ./test
```

- For unit testing the `Gender` class, use the following commands :

```shell
$ g++ -std=c++11 Gender.cpp UnitTestGender.cpp -o test
$ ./test
```

- For unit testing the `Name` class, use the following commands :

```shell
$ g++ -std=c++11 Name.cpp Exceptions.cpp UnitTestName.cpp -o test
$ ./test
```

- For unit testing the `Passenger` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestPassenger.cpp -o test
$ ./test
```

- For unit testing the `BookingClass` hierarchy, use the following commands :

```shell
$ g++ -std=c++11 BookingClass.cpp UnitTestBookingClass.cpp -o test
$ ./test
```

- For unit testing the `BookingCategory` and `Divyaang` hierarchy, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBookingCategory.cpp -o test
$ ./test
```

- For unit testing the `Concession` hierarchy, use the following commands :

```shell
$ g++ -std=c++11 Concession.cpp Date.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Gender.cpp Name.cpp Booking.cpp Station.cpp Railways.cpp Exceptions.cpp UnitTestConcession.cpp -o test
$ ./test
```

- For unit testing the `Booking` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBooking.cpp -o test
$ ./test
```