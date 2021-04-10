/*
Yifeng Qin
CS202_project8
Christos Papachristos
11/16/17

*/
#include "NodeList.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
using namespace std; 

NodeList::NodeList(){
      m_head = new Node; 
      m_head = NULL;
      
}
    
NodeList::NodeList(size_t count, const DataType& value){
   
size_t i = 0;
int c =0;

     if(count)
     {
     	m_head = new Node(value);
      	Node *current = m_head;
      	
		  	while(i < count)
		  	{
		    current->m_next = new Node(value); //allcoates memory for it
		    current = current->m_next;
		    i=i+1;
		    c++;
      		}
      
      }
      else{

        m_head = NULL;
      }
     
}

NodeList::NodeList(const NodeList& other){
     
      if(other.m_head != NULL)
      {
		  Node* otherCurr = other.m_head;
		  m_head = new Node(other.m_head -> m_data);
		  Node *current = m_head;

		  while(otherCurr != NULL){

		    current->m_next = new Node(otherCurr->m_next->m_data); // traverses the node to get to where it wants
		    otherCurr = otherCurr->m_next;
		    current = current->m_next;
		  }
     }
}

NodeList::~NodeList(){

	if(m_head != NULL){

		Node* temp = m_head->m_next;
		delete m_head;
		m_head = temp;	
	}

}

NodeList& NodeList::operator= (const NodeList& rhs){
      //check if something is in there to delete it
  	if(rhs.m_head != NULL)
    {
       Node *current = rhs.m_head;
       Node* temp = rhs.m_head->m_next;

      	while(temp != NULL){

		    delete current;
		    temp = temp->m_next; 
		    current = temp; 
   	 	}
     }

Node *otherCurr = rhs.m_head; 
m_head = new Node(rhs.m_head -> m_data); 
Node *curr = m_head;

	while(rhs.m_head != NULL){

        curr->m_next = new Node(otherCurr->m_next -> m_data);
        otherCurr = otherCurr->m_next;
        curr = curr->m_next;
    }

	return *this;
}

Node* NodeList::First(){

      return m_head; 
}
    
Node* NodeList::Last(){
      
Node * current = m_head;
      
	while(m_head != NULL){

        current = current->m_next; 
    }
      
	return current;

}
    
Node* NodeList::Find(const DataType & target, Node * & previous, const Node * start){
     //need a current Node to keep track of something
     //previous for insertion reasons 
	return NULL;
}

Node* NodeList::InsertAfter(const DataType& target, const DataType& value){
      
	size_t k = size() + 1;
	for(size_t i = 0; i < size(); i ++){
		if(target /* temp */ == target){
			Node* temp1;
			temp1 = new Node();
			for(size_t z = size(); z > 0 ; z--){ 
		
				temp1[z] = m_head[z];// puts into temp 
			}
		
			temp1[k] = value;
			return temp1;
		}
		
		else{

			return NULL;
		}
	}
	return m_head;
}
   
Node* NodeList::InsertBefore(const DataType& target, const DataType& value){
  
	for(size_t i = 0; i < size(); i ++){
		if(target /* temp */ == target){
			Node* temp1;
			temp1 = new Node();
			for(size_t z = size(); z > 0 ; z--){ 
		
				temp1[z + 1] = m_head[z];// puts into temp 
			}
		
			temp1[0] = value;
			return temp1;
		}
		
		else{

			return NULL;
		}
	}
return m_head;
}                  
    
Node* NodeList::Erase(const DataType& target){
      
	for(size_t i = 0; i < size(); i ++){
		if(target /* temp */ == target){
			Node* temp2;
			temp2 = new Node();
			delete [] temp2 ;// deletes the array
		
			return temp2;
		}
		
		else{

			return NULL;
		}
	}
	return m_head;
}
	
DataType& NodeList::operator[] (size_t position){
Node* temp = m_head;

	for(size_t i = 0; i < position; i++){
	
		temp =  temp -> m_next;
	}

	return temp -> GetData();
}

const DataType& NodeList::operator[] (size_t position) const{
    
Node* temp = m_head;

	for(size_t i = 0; i < position; i++){
	

		temp =  temp -> m_next;// traverses the node to get to getData

	}

	return temp -> GetData();
}

size_t NodeList::size() const{

size_t sizeCount; 

Node *curr = m_head;
      while(curr != NULL){ // uses while loop to get to end of array

        sizeCount++;
      }

      return sizeCount;
}
    
bool NodeList::empty() const{
      
	if(m_head != 0){

        return false; 
    }

	else{

      return false; 

	}
}

void NodeList::clear(){
    
	delete [] m_head;

}

std::ostream& operator<<(std::ostream& os, const NodeList& nodeList){
   /*
	Node* something = nodeList.m_head;

	for(size_t i = 0; i < nodeList.size(); i++){
	

		something = something -> m_next;

		os << something -> GetData() << endl;

	}
*/

	os << nodeList.m_head << endl;
		return os;
}
