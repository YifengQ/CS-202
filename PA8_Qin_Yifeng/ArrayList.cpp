/*
Yifeng Qin
CS202_project8
Christos Papachristos
11/16/17

*/

#include "ArrayList.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

ArrayList::ArrayList(){
	m_size = 0;
	m_maxsize = 100;
	m_array = NULL;

}	

//////////////////////////PROBLEMS?????????	
					    		//(1)
ArrayList::ArrayList(size_t count, const DataType& value){
	m_array = NULL;
	m_array = new DataType[count];//allcoates memory
	m_size = count;
	m_maxsize = 100;

	for(size_t i= 0; i < m_size; i++){

		m_array[i] = value; // for all the values, they are set the same
	}

	

}			//(2)
ArrayList::ArrayList(const ArrayList& other){
	
	this -> m_array = new DataType[other.m_size]; // allocates the same memory
	
	for(size_t i= 0; i < other.m_size; i++){

		this->m_array[i] = other.m_array[i];// sets the values to the same
	}
	this->m_size = other.m_size;
	this->m_maxsize = other.m_maxsize;

}			    	//(3)
ArrayList::~ArrayList(){

	delete [] m_array;
}						    			//(4)

ArrayList& ArrayList:: operator= (const ArrayList& rhs){

	this -> m_array = new DataType[rhs.m_size]; // allocates the same memory
	
	for(size_t i= 0; i < rhs.m_size; i++){

		m_array[i] = rhs.m_array[i]; // sets the values to the same
	}
	this -> m_size = rhs.m_size;
	this -> m_maxsize = rhs.m_maxsize;

	return *this;
}		//(5)


DataType* ArrayList :: First(){
	
	if(m_array == NULL){

		return NULL;	
	}
	
	else{
	
		return& m_array[0]; // accesses the first position
	}
}							     		//(6)
DataType* ArrayList:: Last(){

	if(m_array == NULL){

		return NULL;	
	}
	
	else{
	
		return& m_array[m_size];// accesses the last postition
	}
}						                //(7)

DataType* ArrayList::Find(const DataType & target, DataType * & previous, const DataType * start ){

	for(size_t i = 0; i < m_maxsize ; i++){
		
		if(m_array[i] ==  target){
			*previous = m_array[i-1];

			return& m_array[i]; // returns the postion that its at
	
	}
		}
	
	previous = NULL;

	return NULL;
}

DataType* ArrayList:: InsertAfter(const DataType& target, const DataType& value){
	
	for(size_t i = 0; i < m_size ; i++){
		if(m_array[i] == target){
			
			DataType* temp; // makes a temp storage
			size_t size = m_size + 1;
			resize(size);
			m_size = size;
			temp = new DataType[size];
			for(size_t z = m_size; z > m_size ; z--){ 
		
				temp[z] = m_array[z];// puts into temp 
			}
			
			temp[i + 1] = value;
				cout << temp[i + 1] << endl; //adds it after the temp
		return temp;

		}

		
		else{

			return NULL;
		}
	
	}

	return m_array;
	

	/*size_t size = m_size + 1;
	m_array = new DataType[size];

		for(size_t i = 0; i < size; i++){

			m_array[i] = target;
		}

		m_array[size] = value;
		m_size = size;
		return m_array;

		*/
}

DataType* ArrayList:: InsertBefore(const DataType& target, const DataType& value){
	
	for(size_t i = 0; i < m_size ; i++){
		if(m_array[i] == target){
			
			DataType* temp; // makes a temp storage
			size_t size = m_size + 1;
			resize(size);
			m_size = size;
			temp = new DataType[size];
			for(size_t z = m_size; z > m_size ; z--){ 
		
				temp[z] = m_array[z + 1];// puts into temp 
			}
			
			temp[i] = value;
				cout << temp[i] << endl; //adds it after the temp
		return temp;

		}

		
		else{

			return NULL;
		}
	
	}

	return m_array;
}

DataType* ArrayList:: Erase(const DataType& target){

	for(size_t i = 0; i < m_size ; i++){

		if(m_array[i] == target){

			return m_array;// returns the array at that postion
		}

		else{

			return NULL;
		}
	}
return m_array;
}


DataType& ArrayList:: operator[] (size_t position){

	
	return m_array[position]; // returns the array at that postion
}					//(12)

size_t ArrayList::size() const{

	return m_size; // gets the size from m_size
}
						//(13)
bool ArrayList::empty() const{

	if(m_size > 0){ // checks if it is empty

		return false;
	}

	else{

		return true;
	}
}									//(14)
void ArrayList::clear(){


	delete [] m_array;
}

void ArrayList::resize(size_t count){

	delete [] m_array;

	m_array = new DataType[count];
/*
	if(count > m_size){

		for(size_t i = 0; i < m_size; i++){

			m_array[i] = NULL;		
	
		}

	}
*/
}

std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList){
	
	for(size_t i =0 ; i < arrayList.m_size ; i++){
		
		os << "{" << arrayList.m_array[i] << "}";
	}

	return os;
}
