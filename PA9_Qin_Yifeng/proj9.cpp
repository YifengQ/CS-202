	/*
	Yifeng Qin
	CS202_project9
	Christos Papachristos
	11/16/17

*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main()
{

	cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Array   	  /////\n" <<
          "////////////////////////////" << endl;

	DataType test1;
	test1 = DataType(1, 0.8);

	cout << "Default constructor" << endl;
	ArrayQueue test2;
	cout << "ArrayQueue: " << test2 << endl;


	cout << "Parametrized constructor" << endl;
	ArrayQueue test4(3, test1);
	cout << "ArrayQueue: " << test4 << endl;


	cout << "Copy constructor" << endl;
	ArrayQueue test6(test4);
	cout << "ArrayQueue: " << test6 << endl;


	cout << "Equal operator" << endl;
	ArrayQueue test7;
	test7 = test6;
	cout << "ArrayQueue: " << test7 << endl;


	cout << "Front" << endl;
	DataType test8;
	DataType test9;
	test8 = test4.front();
	cout << "ArrayQueue: " << test8 << endl;
	
	cout << "Back" << endl;
	DataType test10;
	DataType test11;
	test10 = test4.back();
	cout << "ArrayQueue: " << test10 << endl;

	  
	cout << "Push" << endl;
	DataType test12(1, 1.0);
	test4.push(test12);
	cout << "ArrayQueue: " << test4 << endl;
	

	cout << "Pop" << endl;
	test4.pop();
	cout << "ArrayQueue: " << test4 << endl;


	cout << "Size" << endl;
	cout << "ArrayQueue: " << test4.size() << endl;


	cout << "Empty" << endl;
	cout << boolalpha << test4.empty() << endl;


	cout << "Full" << endl;
	cout << boolalpha << test4.full() << endl;

	cout << "Clear" << endl;
	test4.clear();
	cout << "ArrayQueue: " << test4;
	 

	/////////////////////
	cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Node          /////\n" <<
          "////////////////////////////" << endl;

	cout << "Default constructor" << endl;
	NodeQueue test3;
	cout << "NodeQueue: " << test3 << endl;

	cout << "Parametrized constructor" << endl;
	NodeQueue test5(1, test1);
	cout << "NodeQueue: " << test5 << endl;
	
	cout << "Copy constructor" << endl;
	NodeQueue test6n(test5);
	cout << "NodeQueue: " << test6n << endl;

	cout << "Equal operator" << endl;
	NodeQueue test7n;
	test7n = test5;
	cout << "NodeQueue: " << test7n << endl;

	cout << "Front" << endl;
	DataType test8n;
	DataType test9n;
	test8n = test5.front();
	cout << "NodeQueue: " << test8n << endl;

	cout << "Back" << endl;
	DataType test10n;
	DataType test11n;
	test10n = test5.back();
	cout << "NodeQueue: " << test10n << endl;

	cout << "Push" << endl;
 	DataType test12n(2, 2.3);
	test5.push(test12n);
	cout << "NodeQueue: " << test5 << endl;
	cout << "Pop" << endl;
	test5.pop();
	cout << "NodeQueue: " << test5 << endl;

	cout << "Size" << endl;
	cout << "NodeQueue: " << test5.size() << endl;
 
	cout << "Empty" << endl;
	cout << boolalpha << test5.empty() << endl;

	cout << "Full" << endl;
	cout << boolalpha << test5.full() << endl;

	cout << "Clear" << endl;
 	test5.clear();
	cout << "NodeQueue: " << test5 << endl; 

return 0;
	}


























