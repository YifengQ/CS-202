#include "Car.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;


void Car::setPlate(const char* temp_plate)
{
	strcpy (m_plates, temp_plate);	
}

const char* Car::getPlate() const
{

return m_plates;
}

//default constructor
Car::Car()
{
	//sets all the varaibles to 0 so they don't output random characters
	m_throttle = 0;
	cout << "Car #" << m_vin << " :Default-ctor" << endl;
	m_plates[0]='\0'; 

}

//parameterized constructor
//has to call the vehicle parameterized to set the vin
Car::Car(char* t_plate, int t_num, float *t_lla): Vehicle(t_num, t_lla)
{
	//calls the set plate function and passes the value from the main to the m_vin
	setPlate(t_plate);
	cout << "Car #" <<  m_vin << " Parameterized-ctor" << endl;

}

//destructor
Car::~Car()
{
	cout <<"Car #" << m_vin << ": Dtor" << endl;

}

//instertioin operator
//couts the data of the vehicle and everything in it
std::ostream& operator << (std::ostream& os, const Car& c1){
	int i = 0;
	int z = 0;
	int length = strlen(c1.m_plates);
	
	os << "Car #" << c1.m_vin << " Plates: ";
	for(z= 0; z < length ; z++)
	{
		cout << c1.m_plates[z] ;

	}

	cout << " @ [  ";

	for(i = 0 ; i < 3 ; i++)
	{
		os << c1.m_lla[i] << " " ;

	}
	os << "]" << endl;
	
	return os;
}

//copy constructor
//takes a copy of the data but makes a new vehicle that is set to s_idgen so no two cars can be the same
Car::Car(const Car &c2) : Vehicle(getID(), m_lla)
{
int i = 0;
int z = 0;
int length = strlen(c2.m_plates);	

	cout << "Car #" << m_vin << ": Copy-ctor" << endl;
	for(i = 0 ; i < 3 ; i++)
	{
	m_lla[i]= c2.m_lla[i];

	}
	for(z= 0; z < length ; z++)
	{
		m_plates[z] = c2.m_plates[z] ;

	}

}

//assigemnet operator
//makes sure that two arent the same and calls the set functions to give the car the plate and location values.
Car& Car::operator = (const Car &c3)
{
	cout << "Car #" << m_vin << " Assignment" << endl;

	if(this == &c3)
	{
		cout << "Error" << endl;
	}
	else
	{
		setLla(c3.getLla());
		setPlate(c3.getPlate());
	}

}

//Drive function
//sets the throttle to a given input
void Car::Drive(int t_throttle)
{

	m_throttle = t_throttle;
}

//Move function
void Car :: Move(float* t_lla)
{
	cout << "Car #"<< m_vin << ": DRIVE to destination, with throttle @ 75" << endl;
	//gives drive a value to set the throttle to 75
	Drive(75);
	

}
