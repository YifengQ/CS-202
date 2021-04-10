/*
Yifeng Qin
CS202_project9
Christos Papachristos
11/16/17

*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "ArrayQueue.h"

using namespace std;

ArrayQueue::ArrayQueue(){
 
	m_size = 0;
	m_front = 0;	// sets eqaul to 0 so they aren't random
	m_back = 0;
}
                                           
ArrayQueue::ArrayQueue(size_t count, const DataType& value){
	
	m_front = m_size; 	//sets the front to the size of pervious size
	size_t temp = count - 1; 	//minus one because of array counting
	m_back = m_size + temp; 	//sets back to size of array
  	m_size = m_size + count;		//sets the size
  
  	for(size_t i = m_front; i <= m_back; i++){	//runs for size given

  	  m_array[i] = value;	//sets the values for set amount that was given 
 	 }
}
            
ArrayQueue::ArrayQueue(const ArrayQueue& other){	

	size_t temp = other.size();	//gets the size of last array	
	m_front = other.m_size;	//sets front to one more to not overlap with previous one
	m_back = other.m_size + temp - 1;	//minus one because of array 
	m_size = m_back + 1;	//gets actal amount of objects

 	for(size_t i = m_front; i <= m_back; i++){	//runs for size given

  	 m_array[i] = other.m_array[i - temp];
 	}
}
                        
ArrayQueue::~ArrayQueue(){
}
                                         
ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs){

  if(this != &rhs){

 	size_t temp = rhs.size();	//gets the size of last array	
	m_front = rhs.m_size;	//sets front to one more to not overlap with previous one
	m_back = rhs.m_size + temp - 1;	//minus one because of array 
	m_size = m_back + 1;	//gets actal amount of objects
	
 	for(size_t i = m_front; i <= m_back; i++){	//runs for size given
	
  	 m_array[i] = rhs.m_array[i - temp]; // sets data to what was before it
 	}
  }
  
	
}
             
DataType& ArrayQueue::front(){

  if(!empty()){		// checks if it is empty

    return m_array[m_front];	// returns what is in the front of queue
  }
}
                                      
const DataType& ArrayQueue::front() const{

  if(!empty()){

    return m_array[m_front];
  }
}
                            
DataType& ArrayQueue::back(){

  if(!empty()){		// checks if it is empty
    
	return m_array[m_back];		//returns what is at the back of the queue
  }
}
                                       
const DataType& ArrayQueue::back() const{

  if(!empty()){

    return m_array[m_back];
  }
}
                           
void ArrayQueue::push(const DataType& value){

  if(!full()){	//checks if it is full

    m_back = (m_back+1) % ARRAY_MAX; // will move the other back
    m_array[m_back] = value;
    ++m_size;
  }
  else{
    cout << "Not enough space" << endl; 
  }
}
                        
void ArrayQueue::pop(){

  if(!empty()){		//checks if empty

    m_front = (m_front + 1) % ARRAY_MAX; // will move the front by one
    --m_size;
  }

  else{
    cout << "Queue is empty" <<  endl;
  }
}
                                              
size_t ArrayQueue::size() const{

	size_t temp = m_back - m_front + 1;
  	return temp; 	//returns size
}
                                    
bool ArrayQueue::empty() const{

  if(m_size == 0)	// if size is 0 it is empty
  {

    return true;
  }
  else{

    return false;
  }
}
                                   
bool ArrayQueue::full() const{

  if(m_size == ARRAY_MAX){	// if size is equal max size
    return true;
  }

  else{

    return false;
  }
}
                                   
void ArrayQueue::clear(){

	 m_size = 0;
	 m_back = 0;	//returns to beginning
	 m_front = 0;
}
                                            
void ArrayQueue::serialize(std::ostream& os) const{

  for(size_t i = m_front; i <= m_back; i++){	//runs for size of object

    os << m_array[i];	
  }

	os << endl;
}  

ostream& operator<<(std::ostream& os, const ArrayQueue& arrayQueue){

  arrayQueue.serialize(os);	//calls serialize because it's not member function
  return os;
}












































