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

#include "NodeQueue.h"

using namespace std;


NodeQueue::NodeQueue() {

	m_front = NULL;	// sets eqaul to NULL so they aren't random
	m_back = NULL;
}
                                                                 
NodeQueue::NodeQueue(size_t size, const DataType& value){

	m_front = new Node(value, NULL); 	// allocates space which is m_front
	m_back = m_front; 	// then m_back gets m_front for the next node

	for(size_t i = 0; i < size - 1; i++){ 	// for loop to set the values for amount of items

	Node* new_node = new Node(value, NULL); 	// allocates memory
	m_back -> m_next = new_node; 
	m_back = m_back -> m_next;		//moves to next node
	}
}
              
NodeQueue::NodeQueue(const NodeQueue& other) {

	m_front = new Node(other.m_front -> m_data, NULL); 	// allocates space which is m_front
	//m_back = other.m_front;

	for(Node* curr = other.m_front -> m_next; curr != NULL; curr = curr -> m_next){	//moves to back of node

	m_back  = new Node(curr -> m_data, NULL);	// allocates memory
	m_back = m_back -> m_next;		//moves to next node
	}
}
                          
NodeQueue::~NodeQueue(){

  delete [] m_front;
}
                                          
NodeQueue& NodeQueue::operator= (const NodeQueue& rhs){ 
  
	if(this != &rhs){	//checks if it is the same node

	 this -> clear();
	m_front = new Node(rhs.m_front -> m_data, NULL);
	for(Node* curr = rhs.m_front; curr != NULL; curr = curr -> m_next){	//moves to back of node

	  m_back = new Node(curr -> m_data, NULL);	// allocates memory
	  m_back = m_back -> m_next;	//moves to next node
	}
	}

	return *this;
}
             
DataType& NodeQueue::front(){

	if(!empty()){ // checks if it is empty

	return m_front -> m_data; // returns what is in the front of queue
	}
	}
		                               
	const DataType& NodeQueue::front() const{

	if(!empty()){

	return m_front -> m_data;
	}
}
                            
DataType& NodeQueue::back(){

	if(!empty()){ // checks if it is empty

	return m_back -> m_data; //returns what is at the back of the queue
	}
	}
		                               
	const DataType& NodeQueue::back() const{

	if(!empty()){

	return m_back -> m_data;
	}
}
                           
void NodeQueue::push(const DataType& value){

	Node* node_ptr;
	if(m_back == NULL){ //checks 

	node_ptr = new Node;	//allocates memory
	m_back = node_ptr; 	//moves m_back
	m_front = node_ptr;	//moves m_back
	node_ptr -> m_data = value;	//sets the the new node to value
	}

	else{

	node_ptr = new Node;	//allocates memory
	node_ptr -> m_next = NULL;	//moves to next node thats NULL
	m_back -> m_next = node_ptr;	//moves to next node
	m_back = node_ptr;
	node_ptr -> m_data = value; //sets it equal to value
	}
}
                       
void NodeQueue::pop(){

	if(m_front != NULL){	//checks if its empty

	Node* d_ptr;
	d_ptr = m_front;
	m_front = m_front -> m_next; // moves to next 
	delete d_ptr; // deletes what was there
	}
}
                                             
size_t NodeQueue::size() const{

	Node* temp = m_front;
	int size;

	while(temp != NULL){	// runs unitl end of queue

	temp = temp -> m_next;
	size++; // counts the numbers
	}

	return size;
}
                                    
bool NodeQueue::empty() const{

	if(m_front == NULL && m_back == NULL){ 	//checks if there is values

	return true;
	}
	else{

	return false;
	}
}
                                    
bool NodeQueue::full() const{

    return false; //always return false, no set size
}
                                    
void NodeQueue::clear(){

    pop(); // pops the queue
}
                                            
void NodeQueue::serialize(std::ostream& os) const{

	Node* print;
	print = m_front;

	while(print != NULL){ // runs till end of queue
	
		os << print -> m_data;
		print = print -> m_next; //couts the data
	}

	os << endl;
}

std::ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue){

	nodeQueue.serialize(os); //calls serialize cause, i doesnt have access to private members
	return os;
}













































