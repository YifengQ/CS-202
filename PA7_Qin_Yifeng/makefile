all:	proj7

proj7:	proj7.o	MyString.o
	g++ proj7.o	MyString.o	-o	proj7

MyString.o:	MyString.cpp	MyString.h	
	g++ -c 	MyString.cpp

clean:
		rm	-rf	*.o	proj7
