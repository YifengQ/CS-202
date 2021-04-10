/*
Yifeng Qin
CS202 - 1104
project 6
MyString cpp File
10/25/17
*/

#include "MyString.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

//default
MyString::MyString(){
	
	m_size = 0;	//sets the size to zero
	m_buffer = NULL; //makes sure the array has nothing
}                                                             
	//parameterized
MyString::MyString(const char* str){
	
	size_t str_len = strlen(str);	//gets the length of the string
	
	buffer_allocate(str_len); //allocates memory based on the size given
	strcpy(m_buffer, str);	// copies the string to the array
}
	//copy
MyString::MyString(const MyString& other_myStr){

	size_t size = other_myStr.size();	 // gets the size from the size function 
	this -> buffer_allocate(size);	//allocates memory based on the size given
	strcpy(m_buffer, other_myStr.m_buffer);		// copies the string to the array
	
}
	//destructor
MyString::~MyString(){

	buffer_deallocate(); // deallocates memory
}
//return size
size_t MyString::size() const{
	
	size_t size = strlen(m_buffer);	//gets the lenght of the string
	return size + 1;	//returns size
}
//return lenth	
size_t MyString::length() const{

	size_t size = strlen(m_buffer);	//gets the lenght of the string
	return size;	//returns size without null character
}
//return car pointer
const char* MyString::c_str() const{

	return m_buffer;
}
	
//check if objects are the same
bool MyString::operator== (const MyString& other_myStr) const{

	if(this == &other_myStr){ 	//checks it the two objects are the same

		return false;
	}
	
	return true;
}
//assign a new value
MyString& MyString::operator= (const MyString& other_myStr){
	
	size_t size = strlen(other_myStr.c_str());
	buffer_allocate(size);	//allocates memory based on the size given
	strcpy( m_buffer, other_myStr.c_str());
	
}
//assign new value to another 
MyString MyString::operator+ (const MyString& other_myStr) const{
	
	char *buffer = m_buffer; // a temp array to store m_buffer
	size_t size = m_size + other_myStr.length(); //gets size of the two arrays together
	char *array = NULL;
	array = new char [size];
	//buffer_allocate(size);//allocates memory based on the size given
	strcpy(array, buffer);	// copies the string to the array
	strcat(array, other_myStr.m_buffer);	// appends the string to the array

	return array;	

	delete [] array;
}
//access a specific character index
char& MyString::operator[] (size_t index){

	return m_buffer[index];	//allows maipulation without the const
}
//access a specific character index
const char& MyString::operator[] (size_t index) const{

	return m_buffer[index];// only read with the const
}

ostream& operator<< (ostream& os, const MyString& myStr){

	cout << myStr.c_str() << endl; // prints out the data for m_buffer
	return os;
}

void MyString::buffer_allocate(size_t size){
	m_buffer = NULL;
	//sets m_buffer to NULL
	try{
	
		m_buffer = new char [size];	//allocates the memory based on the size
	}

	catch(std::bad_alloc & ex){ // checks if it was allocated

		delete [] m_buffer;
		throw;
	}

	m_size = size;	//sets the m_size to size
}

void MyString::buffer_deallocate(){

	delete [] m_buffer;	//deallocates the memory
}

