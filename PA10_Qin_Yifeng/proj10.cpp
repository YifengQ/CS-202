/*
Yifeng Qin
CS202_project10
Christos Papachristos
12/3/17

*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

int main()
{

    cout << "\n" <<
         "////////////////////////////\n" <<
         "/////    Array   	  /////\n" <<
         "////////////////////////////" << endl;

    DataType test1 (1, 0.8);
    DataType test10(1, 1.0);
    cout << "Default constructor" << endl;


    ArrayStack <DataType> test2;
    cout << "ArrayStack: " << test2 << endl;


    cout << "Parametrized constructor" << endl;
    ArrayStack <DataType> test4(3, test1);
    ArrayStack <DataType> test11(2, test10);


    cout << "ArrayStack: " << test4 << endl;


    cout << "Copy constructor" << endl;
    ArrayStack <DataType> test6(test11);
    cout << "ArrayStack: " << test6 << endl;


    cout << "Equal operator" << endl;
    ArrayStack <DataType> test7;
    test7 = test4;
    cout << "ArrayStack: " << test7 << endl;


    cout << "Top" << endl;
    cout << "ArrayStack: " << test4.top() << endl;


    cout << "Push" << endl;
    DataType test12(1, 1.0);
    test4.push(test12);
    cout << "ArrayStack: " << test4 << endl;


    cout << "Pop" << endl;
    test4.pop();
    cout << "ArrayStack: " << test4 << endl;


    cout << "Size" << endl;
    cout << "ArrayStack: " << test6.size() << endl;
    cout << endl;

    cout << "Empty" << endl;
    cout << boolalpha << test4.empty() << endl;
    cout << endl;

    cout << "Full" << endl;
    cout << boolalpha << test4.full() << endl;
    cout << endl;

    cout << "Clear" << endl;
    test4.clear();
    cout << "ArrayStack: " << test4;


    /////////////////////
    cout << "\n" <<
         "////////////////////////////\n" <<
         "/////    Node          /////\n" <<
         "////////////////////////////" << endl;

    cout << "Default constructor" << endl;
    NodeStack <DataType> test3;
    cout << "NodeStack: " << test3 << endl;

    cout << "Parametrized constructor" << endl;
    NodeStack <DataType> test5(3, test1);
    cout << "NodeStack: " << test5 << endl;

    cout << "Copy constructor" << endl;
    NodeStack <DataType> test6n(test5);
    cout << "NodeStack: " << test6n << endl;

    cout << "Equal operator" << endl;
    NodeStack <DataType> test7n;
    test7n = test5;
    cout << "NodeStack: " << test7n << endl;

    cout << "Top" << endl;
    cout << "NodeStack: " <<   test5.top() << endl;

  
    cout << "Push" << endl;
    DataType test12n(2, 2.3);
    test7n.push(test12n);
    cout << "NodeStack: " << test7n << endl;
    
	cout << "Pop" << endl;
    test5.pop();
    cout << "NodeStack: " << test5 << endl;

    cout << "Size" << endl;
    cout << "NodeStack: " << test6n.size() << endl;

    cout << "Empty" << endl;
    cout << boolalpha << test5.empty() << endl;

    cout << "Full" << endl;
    cout << boolalpha << test5.full() << endl;

    cout << "Clear" << endl;
    test5.clear();
    cout << "NodeStack: " << test5 << endl;

    return 0;
}



























