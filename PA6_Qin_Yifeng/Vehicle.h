#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
/*
Yifeng Qin
CS202 - 1104
project 6
Vehicle Header File
10/25/17 
*/

#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

class Vehicle{
	
	public:
	//default
	Vehicle();
	//para
	Vehicle(const float* t_lla);
	//copy
	Vehicle(const Vehicle& v1);
	//dest
	virtual ~Vehicle();
	//assign
	Vehicle& operator = (const Vehicle &v2);
	//get & set for m_lla
	void SetLLA(const float* t_lla);
	const float* getLla() const;

	//insertion
	friend std::ostream& operator << (std::ostream& os, Vehicle& v3);

	//move
	virtual void Move(const float* t_lla);

	//Used to call seriaize
	void Output();


	protected:

	float m_lla[3];
	
	private:
	//private function : serialize
	virtual void Serialize(std::ostream& os);

};

#endif // !VEHICLE_H
