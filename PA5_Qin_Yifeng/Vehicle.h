#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

class Vehicle{
	public:
	//default constructor
	Vehicle();
	//parameterized constructor
	Vehicle(int id, float* t_lla);
	//destructor
	~Vehicle(void);
	//assigemnet operator
	Vehicle& operator = (const Vehicle &v3);
	//Move function	
	void Move(float* t_lla);
	int getID();
	

	//instertioin operator
	friend std::ostream& operator << (std::ostream& os, const Vehicle& v1);

	static int GetIdgen();
	
	void setLla(const float lla[3]);

	const float* getLla() const;

	//copy constructor
	Vehicle(const Vehicle &v2);

	protected:
	float m_lla[3];
	const int m_vin;


	private:
	static int generateID(int id){
		return id;	
	}
	
	static int s_idgen;


};


#endif // !VEHICLE_H

