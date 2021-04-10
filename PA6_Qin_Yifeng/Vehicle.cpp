/*
Yifeng Qin
CS202 - 1104
project 6
Vehicle cpp File
10/25/17
*/

#include "Vehicle.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

//default
Vehicle::Vehicle(){

	cout << "Vehicle: Default-ctor" << endl;

}

//para
Vehicle::Vehicle(const float* t_lla){
	//calls the set function and passes in the t_lla
	SetLLA(t_lla);
	cout << "Vehicle: Parameterized-ctor" << endl;
}

//copy
Vehicle::Vehicle(const Vehicle& v1){
	//calls the set function for lla and uses the get function for the value
	cout << "Vehicle: Copy-ctor" << endl;
	SetLLA(v1.getLla());
	
}

//destr
Vehicle::~Vehicle(){

	cout << "Vehicle: Dtor" << endl;
}

//set & get for lla
void Vehicle::SetLLA(const float* t_lla){
	//for loop to take all 3 values in t_lla and move copy them into m_lla
	for(int i = 0 ; i < 3 ; i++, t_lla++){
		
		m_lla[i] = *t_lla;
	}
	
}

const float* Vehicle::getLla()const{

	return m_lla;	
}

//assign
Vehicle& Vehicle:: operator = (const Vehicle& v2){
	//checks if the objects aren't the same	
	if(this != &v2){
		
		SetLLA(v2.getLla());//calls the set function to set the values
	}
	else{
		cout << "error" << endl;
	}
	cout << "Vehicle: Assignment" << endl;
	return *this;
}

std::ostream& operator << (std::ostream& os, Vehicle& v3){
	//calls the output that calls the serialize
	v3.Output();
	return os;
	
}

void Vehicle::Move(const float* t_lla){
	//sets the lla 
	SetLLA(t_lla);
}

void Vehicle::Output(){
	//need this function because the insertion operator is not a member function
	Serialize(std::cout);
}

void Vehicle::Serialize(std::ostream& os){
	//prints out all the data in a for loop for the appropriate vehicle
	for(int i = 0 ; i < 3 ; i++){
	
		os <<"Vehicle @ [" << m_lla[i] << ", " ;
	}
	os << "]" << endl;
	
}


