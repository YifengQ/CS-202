//Yifeng Qin
//CS202
//ProjectX

#include "SmartPtr.h"


#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;


SmartPtr::SmartPtr(){
  
	*m_refcount = 1;
	m_ptr = NULL;
	*m_refcount++;

}

SmartPtr::SmartPtr( DataType * data ){
  	if(m_ptr == NULL){


		*m_refcount = 0;
	}

	else{

		*m_refcount = 1;
	}
	cout << "SmartPtr Parameterized Constructor from data pointer, RefCount= " << m_refcount << endl;

}

SmartPtr::SmartPtr(const SmartPtr& other){

	
	cout << "SmartPtr Copy Constructor, RefCount= " << m_refcount << endl;
}

SmartPtr:: ~SmartPtr(){
	
	delete [] m_refcount;
	cout << "SmartPtr Destructor, RefCount= " << m_refcount << endl;
}

SmartPtr& SmartPtr:: operator= (const SmartPtr& rhs){


}

DataType& SmartPtr:: operator*(){

	DataType* data_pt = new DataType;
	DataType& data_ref = *(data_pt);
	
	return *data_pt;
}

DataType* SmartPtr:: operator->(){


	DataType* data_pt = new DataType;
	int intVar = data_pt -> GetIntVal();
	try{
	
		m_refcount = new size_t [intVar];	//allocates the memory based on the size
	}

	catch(std::bad_alloc & ex){ // checks if it was allocated

		delete [] m_refcount;
		throw;
	}
	SmartPtr data;
	int Var = data -> GetIntVal();

	return data_pt;
}

