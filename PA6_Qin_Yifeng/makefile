all:	proj6

proj6:	proj6.cpp	Vehicle.o	Vehicle.h	Car.o	Car.h
		g++ proj6.cpp	Vehicle.o	Car.o	-g	-o	proj6

Vehicle.o:	Vehicle.cpp
		g++ -c 	Vehicle.cpp	-g

Car.o:	Car.cpp
		g++	-c	Car.cpp	-g

clean:
		rm	-rf	*.o	proj6
