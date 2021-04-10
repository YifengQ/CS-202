all:	proj9

proj9:	proj9.o	ArrayQueue.o NodeQueue.o DataType.o
	g++ proj9.o	ArrayQueue.o	NodeQueue.o	DataType.o	-o	proj9

ArrayQueue.o:	ArrayQueue.cpp	ArrayQueue.h	
	g++ -c 	ArrayQueue.cpp

NodeQueue.o:	NodeQueue.cpp	NodeQueue.h	
	g++ -c NodeQueue.cpp

DataType.o:	DataType.cpp	NodeQueue.h	
	g++ -c DataType.cpp

clean:
		rm	-rf	*.o	proj9
