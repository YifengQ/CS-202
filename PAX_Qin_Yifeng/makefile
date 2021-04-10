all:	projX

projX:	projX.o	DataType.o SmartPtr.o
	g++ projX.o	DataType.o SmartPtr.o	-o	projX

DataType.o:	DataType.cpp	DataType.h	
	g++ -c 	DataType.cpp

SmartPtr.o: SmartPtr.cpp	SmartPtr.h
	g++ -c SmartPtr.cpp

clean:
		rm	-rf	*.o	projX
	
