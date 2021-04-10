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
	Car(char* t_plate, int t_num, float *t_lla);
	//copy constructor
	Car(const Car &c2);
	//assigemnet operator
	Car& operator = (const Car &c3);
	//destructor
	~Car();
	
	void setPlate(const char* temp_plate);
	const char* getPlate() const;
	//instertioin operator
	friend std::ostream& operator << (std::ostream& os, const Car& c1);
	//Drive function
	void Drive(int t_throttle);
	//Move function
	void Move(float* t_lla);

	private:
	char m_plates[255];
	int m_throttle;


};



#endif // !CAR_H
