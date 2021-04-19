CC = g++ -std=c++11
APPFILE = Application

rbs: Station.o Railways.o Date.o BookingClasses.o Booking.o $(APPFILE).o
	$(CC) Station.o Railways.o Date.o BookingClasses.o Booking.o $(APPFILE).o -o rbs

Station.o: Station.cpp Station.h Railways.h
	$(CC) -c Station.cpp

Railways.o: Railways.cpp Railways.h Station.h
	$(CC) -c Railways.cpp

Date.o: Date.cpp Date.h
	$(CC) -c Date.cpp

BookingClasses.o: BookingClasses.cpp BookingClasses.h
	$(CC) -c BookingClasses.cpp

Booking.o: Booking.cpp Booking.h Station.h Railways.h Date.h BookingClasses.h Passenger.h
	$(CC) -c Booking.cpp

$(APPFILE).o: $(APPFILE).cpp Station.h Railways.h Date.h BookingClasses.h Passenger.h Booking.h
	$(CC) -c $(APPFILE).cpp

clean: 
	rm *.o rbs