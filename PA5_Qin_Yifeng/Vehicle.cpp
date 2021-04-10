#include "Vehicle.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

int Vehicle::s_idgen=0;

/////////////////Vehicle///////////////////Vehicle///////////////////////Vehicle//////////////
void Vehicle::setLla(const float lla[3])
{
	//takes in the data and moves it into the array
	int i = 0;
	for(i = 0 ; i < 3 ; i++)
	{
		m_lla[i] = lla[i];
	}
	
	s_idgen++;
}

const float* Vehicle::getLla() const
{
	return m_lla;
}

//default constructor
Vehicle::Vehicle() : m_vin(++s_idgen){
	//sets all the data to zero / uninitalized
	int i =0;
	cout <<"Vehicle #" << m_vin << ": Default-ctor" << endl; 
	for(i = 0 ; i < 3 ; i++)
	{
		m_lla[i] = 0;

	}

}

//parameterized constructor
Vehicle::Vehicle(int id, float* lla) : m_vin(generateID(id) > s_idgen ? generateID(id) : s_idgen){
	int i = 0;
	int z = 0;

	cout <<"Vehicle #" << m_vin << ": Parameterized-ctor" << endl;
	//calls the set function to copy the lla to the m_lla
	setLla(lla);

	++s_idgen;
}

//instertioin operator
//couts the data of the vehicle and everything in it
std::ostream& operator << (std::ostream& os, const Vehicle& v1){
	int i = 0;
	
	os << "Vehicle #" << v1.m_vin << " @ [ ";
	
	for(i = 0 ; i < 3 ; i++)
	{
		os << v1.m_lla[i] << " " ;

	}
	os << "]" << endl;
	
	return os;
}

int Vehicle::GetIdgen()
{

return s_idgen;

}

//copy constructor
//takes a copy of the data but makes a new vehicle that is set to s_idgen so no two cars can be the same
Vehicle::Vehicle(const Vehicle &v2) : m_vin(v2.s_idgen)
{
	int i = 0;
	
	cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
	for(i = 0 ; i < 3 ; i++)
	{
		m_lla[i] = v2.m_lla[i];

	}

}

//destructor
Vehicle::~Vehicle(void)
{
	cout <<"Vehicle #" << m_vin << ": Dtor" << endl;
}

//assigemnet operator
Vehicle& Vehicle :: operator = (const Vehicle &v3)
{
//makes sure they arent equal to each other and then will set the lla for that vehicle
	cout << "Vehicle #" << m_vin << " Assignment" << endl;

	if(this == &v3)
	{
		cout << "Error" << endl;
	}
	else
	{
		setLla(v3.getLla());
	}
}

//Move function
void Vehicle :: Move(float* t_lla)
{

	cout << "Vehicle #"<< m_vin << ": CANNOT MOVE - DON'T KNOW HOW" << endl;
}

int Vehicle :: getID(){
		return m_vin;
	}
