/*
Yifeng Qin
CS202_project8
Christos Papachristos
11/16/17

*/


#include "ArrayList.h"
#include "NodeList.h"


#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

int main(){
cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    DataType   /////\n" <<
          "////////////////////////////" << endl;


cout << "Default C-tor" << endl;
DataType test0;
cout << test0 << endl;

cout << "Paramaerized C-tor" << endl;
DataType test1(1,3);
DataType test100(2,2);
DataType test200(3,3);
DataType test201(4,3);
cout << test1 << endl;

cout << "operator ==" << endl;
if (test0==test1){

    cout << "Equality: Same success" << endl;
  }

else{
    
	cout << "Different" << endl;
}

cout << "operator =" << endl;
DataType test2(test1);
cout << test2 << endl;

DataType test3;
cout << "SetIntVal" << endl;
test3.SetIntVal(10);

cout << "GetIntVal" << endl; 
cout << test3.GetIntVal() << endl;

DataType test4;
cout << "SetDoubleVal" << endl;
test4.SetDoubleVal(11.1);

cout << "GetDoubleVal" << endl; 
cout << test4.GetDoubleVal() << endl;

cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    ArrayList 	  /////\n" <<
          "////////////////////////////" << endl;

cout << "Default C-tor" << endl;
ArrayList test7;
cout << test7 << endl;

cout << "Paramaerized C-tor" << endl;
ArrayList test8(4, test1);
cout << test8 << endl;

cout << "Copy C-tor" << endl;
ArrayList test9(test8);
cout << test9 << endl;

cout << "operator =" << endl;
ArrayList test10(test9);
cout << test10 << endl;

cout << "first" << endl;
cout << test10.First()  << endl;

cout << "last" << endl;
cout << test10.Last()  << endl;

cout << "Find" << endl;
//test10.Find(test1, test2, test0);

cout << "InsertAfter" << endl;
cout << test200 << endl;
test10.InsertAfter(test200, test100);
cout << test200 << endl;

cout << "InsertBefore" << endl;
//cout << test2 << endl;
cout << test10.InsertBefore(test2, test100) << endl;
cout << test2 << endl;
cout << "Erase" << endl;
cout << test10.Erase(test1) << endl;

cout << "operator []" << endl;
test10[2];
cout << test10 << endl;

cout << "size" << endl;
cout << test9.size() << endl;
 
cout << "empty" << endl;
cout << boolalpha << test9.empty() << endl;

cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    NodeList 	  /////\n" <<
          "////////////////////////////" << endl;

cout << "Default C-tor" << endl;
Node test300;

cout << "Paramaterized C-tor" << endl;

cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    NodeList 	  /////\n" <<
          "////////////////////////////" << endl;

cout << "Default C-tor" << endl;
NodeList test20;
cout << test20 << endl;

cout << "Paramaterized C-tor" << endl;
NodeList test21(1, test200);
cout << test21 << endl;

cout << "Copy C-tor" << endl;
NodeList test22(test21);
cout << test22 << endl;

cout << "operator =" << endl;
NodeList test23(test22);
cout << test23 << endl;

cout << "first" << endl;
cout << test23.First()  << endl;

cout << "last" << endl;
cout << test23.Last()  << endl;

cout << "Find" << endl;
//test10.Find(test1, test2, test0);

cout << "InsertAfter" << endl;
cout << test200 << endl;
test23.InsertAfter(test200, test100);
cout << test200 << endl;

cout << "InsertBefore" << endl;
//cout << test2 << endl;
cout << test10.InsertBefore(test2, test100) << endl;
cout << test2 << endl;
cout << "Erase" << endl;
cout << test10.Erase(test1) << endl;

cout << "operator []" << endl;
test23[2];
cout << test23 << endl;

cout << "size" << endl;
cout << test23.size() << endl;
 
cout << "empty" << endl;
cout << boolalpha << test23.empty() << endl;

  return 0;

}
