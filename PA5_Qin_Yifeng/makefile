all:	proj5

proj5:	proj5.cpp	Vehicle.o	Vehicle.h	Car.o	Car.h
		g++ proj5.cpp	Vehicle.o	Car.o	-g	-o	proj5

Vehicle.o:	Vehicle.cpp
		g++ -c 	Vehicle.cpp	-g

Car.o:	Car.cpp
		g++	-c	Car.cpp	-g

clean:
		rm	-rf	*.o	proj5
