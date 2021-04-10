/*
Yifeng Qin
CS202 - 1104
project 6
CAR Header File
10/25/17
*/


#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;


class Car : public Vehicle{

	public:
	//default constructor
	Car();
	//parameterized constructor
	Car(const float *t_lla);
	//copy constructor
	Car(const Car &c2);
	//assigemnet operator
	Car& operator = (const Car &c3);
	//destructor
	virtual ~Car();
	
	//instertioin operator
	//friend std::ostream& operator << (std::ostream& os, const Car& c1);
	//Drive function
	void Drive(int t_throttle);
	//Move function
	void Move(const float* t_lla);

	void setThrottle(int throttle);
	int getThrottle() const;
	private:
	//Override virtual serilaize
	void Serialize(std::ostream& os);
	int m_throttle;


};

#endif // !CAR_H
