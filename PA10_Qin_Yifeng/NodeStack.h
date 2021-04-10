/*
Yifeng Qin
CS202_project10
Christos Papachristos
12/3/17

*/

#ifndef INC_202_PROJ10_NODESTACK_H
#define INC_202_PROJ10_NODESTACK_H

#include <iostream>
#include <ostream>
#include <assert.h>
#include "DataType.h"

using namespace std;

template <class N>	//forward declaration
class NodeStack;

template <class N>
std::ostream &operator<<(std::ostream &os, const NodeStack<N> &nodeStack);

template <class N>
class Node {
    friend class NodeStack<N>;

public:
    Node() : m_next( NULL )
    {
    }

    Node(const N& data, Node<N>* next = NULL) :
            m_next( next ),
            m_data( data )
    {
    }

    N& GetData(){  //gets non-const reference, can be used to modify value of underlying data
        //return const_cast<DataType&>(static_cast<const Node&>(*this).getData());  //an alternative implementation, just for studying reference
        return m_data;
    }

    const N& GetData() const{  //gets const reference, can be used to access value of underlying data
        return m_data;
    }

private:

    Node<N>* m_next;
    N m_data;

};

template <class N>
class NodeStack {

    friend std::ostream &operator<< < >(std::ostream &os, const NodeStack<N> &nodeStack);

public:

    NodeStack();

    NodeStack(size_t count, const N &value);

    NodeStack(const NodeStack<N> &other);

    ~NodeStack();

    NodeStack &operator=(const NodeStack<N> &rhs);

    N &top();

    const N &top() const;

    void push(const N &value);

    void pop();

    size_t size() const;

    bool empty() const;

    bool full() const;

    void clear();

    void serialize(std::ostream &os) const;

private:
    Node<N> *m_top;
};

#endif //INC_202_PROJ10_NODESTACK_H

template <class N>
NodeStack<N>::NodeStack(){

    m_top = NULL;
}

template <class N>
NodeStack<N>:: NodeStack(size_t count, const N& value){

    //m_top = new Node (value, NULL);

    for(size_t i = 0; i < count; i++){ 	// for loop to set the values for amount of items
        Node<N>* new_node = new Node<N>(value, NULL); 	// allocates memory
        new_node -> m_next = m_top;
        m_top = new_node;		//moves to next node
    }

}

template <class N>
NodeStack<N>::NodeStack(const NodeStack<N> &other) {

    m_top = new Node<N>(other.m_top -> m_data, NULL); 	// allocates space which is m_front
    //m_back = other.m_front;

    for(Node<N>* curr = other.m_top -> m_next; curr != NULL; curr = curr -> m_next){	//moves to back of node

        Node<N>* new_node = new Node<N>(curr -> m_data, NULL); 	// allocates memory
        new_node -> m_next = m_top;
        m_top = new_node;		//moves to next node
    }

}

template <class N>
NodeStack<N>::~NodeStack() {

    delete [] m_top;
}

template <class N>
NodeStack<N>& NodeStack<N>::operator=(const NodeStack<N> &rhs) {

    m_top = new Node<N>(rhs.m_top -> m_data, NULL); 	// allocates space which is m_front
    //m_back = other.m_front;

    for(Node<N>* curr = rhs.m_top -> m_next; curr != NULL; curr = curr -> m_next){	//moves to back of node

        Node<N>* new_node = new Node<N>(curr -> m_data, NULL); 	// allocates memory
        new_node -> m_next = m_top;
        m_top = new_node;		//moves to next node
    }

	return* this;
}

template <class N>
N& NodeStack<N> ::top() {

	assert(!empty()); // checks if it is empty, if empty terminate function/program
//was provided in the lecture slides by Christos

	return m_top -> m_data; // returns what is in the front of queue


/*    
	if(!empty()){ // checks if it is empty

        return m_top -> m_data; // returns what is in the front of queue
    }
*/
}


template <class N>
const N& NodeStack<N> ::top() const {

    if(!empty()){ // checks if it is empty

        return m_top -> m_data; // returns what is in the front of queue
    }
}

template <class N>
void NodeStack<N>::push(const N &value) {
	
    Node<N>* node_ptr = new Node<N>(value, m_top); // sets the value to the postion
   	node_ptr -> m_next = m_top;	//inserts a new node
    m_top = node_ptr;	//points to top node

/*
	Node<N>* node_ptr;

	node_ptr = new Node<N>;
	
	node_ptr -> m_data = value;
	node_ptr -> m_next = m_top;
	m_top = node_ptr;

*/	
	
}

template <class N>
void NodeStack<N>::pop() {

    Node<N>* d_ptr;	//makes a new node
    d_ptr = m_top;
    m_top = m_top -> m_next; // moves to next
    delete d_ptr;	//deletes pointer

}

template <class N>
size_t NodeStack<N>::size () const {

    Node<N>* temp = m_top;
    int size = 0;

    while(temp != NULL){	// runs unitl end of stack

        temp = temp -> m_next;
        size++; // counts the numbers
    }

    return size;

}

template <class N>
bool NodeStack<N>::empty() const {

    if(m_top == NULL){ 	//checks if there is values

        return true;
    }
    else{

        return false;
    }

}

template <class N>
bool NodeStack<N>::full() const {

    return false;	//never full
}

template <class N>
void NodeStack<N>::clear(){

	//pop();
    m_top = NULL;
}


template <class N>
void NodeStack<N>::serialize(std::ostream &os) const {

    Node<N>* print;
    print = m_top;

    while(print != NULL){

        os << print -> m_data;	//moves through data
        print = print -> m_next;	//sets to the next one
    }

    os << endl;

}

template <class N>
std::ostream& operator<<(std::ostream& os, const NodeStack<N>& nodeQueue){

    nodeQueue.serialize(os); //calls serialize cause, it doesnt have access to private members
    return os;
}



