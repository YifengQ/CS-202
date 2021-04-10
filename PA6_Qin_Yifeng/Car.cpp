/*
Yifeng Qin
CS202 - 1104
project 6
CAR cpp File
10/25/17
*/

#include "Car.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;


//default constructor
Car::Car(){
	//sets all the varaibles to 0 so they don't output random characters
	setThrottle(0);
	cout << "Car: Default-ctor" << endl;
}

//parameterized constructor

Car::Car(const float* t_lla) : Vehicle(t_lla){ // calls the Vehicle Paramaterized C-tor
	
	cout << "Car: Parameterized-ctor" << endl;
}

//destructor
Car::~Car(){
	
	cout <<"Car: Dtor" << endl;
}

//copy constructor
Car::Car(const Car &c2) : Vehicle(c2){	// Calls the Vehicle Copy-ctor
	
	cout << "Car: Copy-ctor" << endl;
}

//assigemnet operator
//makes sure that two arent the same and calls the set functions to give the car the plate and location values.
Car& Car::operator = (const Car &c3){
	
	Vehicle::operator = (c3);
	cout << "Car: Assignment" << endl;
}

//Drive function
void Car::Drive(int t_throttle){

	setThrottle(t_throttle);	//sets the throttle to a given input
}

//Move function
void Car::Move(const float* t_lla){
	
	SetLLA(t_lla);
	cout << "Car: DRIVE to destination, with throttle @ 75" << endl;
	//gives drive a value to set the throttle to 75
	Drive(75);
	
}

//prints out the data stored in the Car/Vehicle ; m_lla
void Car::Serialize(std::ostream& os){

	os <<"Vehicle @ [";
	for(int i = 0 ; i < 3 ; i++){
	
		  cout << m_lla[i] << " " ;
	}
	os << "]" << endl;
}

void Car::setThrottle(int throttle){

	m_throttle = throttle;
}


int Car::getThrottle() const{

	return m_throttle;
}




