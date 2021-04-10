/*
Yifeng Qin
CS202_project10
Christos Papachristos
12/3/17

*/

#ifndef INC_202_PROJ10_ARRAYSTACK_H
#define INC_202_PROJ10_ARRAYSTACK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "DataType.h"

using namespace std;

const size_t MAX_STACKSIZE = 1000;

template <class A>	//forward declaration
class ArrayStack;

template <class A>
std::ostream &operator<<(std::ostream &os, const ArrayStack<A> &arrayStack);

template <class A>
class ArrayStack {

    friend std::ostream &operator<< <> (std::ostream &os, const ArrayStack<A> &arrayStack);

public:

    ArrayStack();

    ArrayStack(size_t count, const A &value);

    ArrayStack(const ArrayStack<A> &other);

    ~ArrayStack();

    ArrayStack &operator=(const ArrayStack<A> &rhs);

    A& top();

    const A &top() const;

    void push(const A &value);

    void pop();

    size_t size() const;

    bool empty() const;

    bool full() const;

    void clear();

    void serialize(std::ostream &os) const;

private:
    A m_container[MAX_STACKSIZE];
    size_t m_top;
};

#endif //INC_202_PROJ10_ARRAYSTACK_H

template <class A>
ArrayStack<A>::ArrayStack() {

    m_top = 0;
}

template <class A>
ArrayStack<A>::ArrayStack(size_t count, const A &value) {

    m_top = count - 1;
    for(size_t i = 0; i <= m_top; i++){	//runs for how many objects

        m_container[i] = value;	//copies values
    }
}

template <class A>
ArrayStack<A>::ArrayStack(const ArrayStack<A> &other) {

    m_top = other.m_top;
    for(size_t i = 0; i <= m_top; i++){		//runs for size of array

        m_container[i] = other.m_container[i];	//copies values
    }
}


template <class A>
ArrayStack<A>::~ArrayStack() {
//dont need

}

template <class A>
ArrayStack<A>& ArrayStack<A>:: operator= (const ArrayStack<A> &rhs) {

    m_top = rhs.m_top;
    for(size_t i = 0; i <= m_top; i++){	//runs for size of array

        m_container[i] = rhs.m_container[i];	//copies values
    }

	return* this;
}

template <class A>
A& ArrayStack<A>::top() {

    return m_container[m_top];	//returns what is at that position
}

template <class A>
const A& ArrayStack<A>::top() const {

    return m_container[m_top];	//returns what is at that position
}

template <class A>
void ArrayStack<A>::push(const A &value) {

    if(!full()){

        m_top = (m_top + 1) % MAX_STACKSIZE;// increases the space and buts the value in
        m_container[m_top] = value;
        //++m_top;
    }
    else{

        cout << "Not enough Space" << endl;
    }
}

template <class A>
void ArrayStack<A>::pop(){

    if(!empty()){

        m_top = (m_top - 1) % MAX_STACKSIZE; // decreases size to delete one
        --m_top;
    }
    else{

        cout << "empty" << endl;
    }

}

template <class A>
size_t ArrayStack<A>::size() const {


    return m_top + 1; //returns the actual size
}

template <class A>
bool ArrayStack<A>::empty() const {

    return m_top <= 0; //checks if it is empty
}

template <class A>
bool ArrayStack<A>::full() const {

    return m_top >= MAX_STACKSIZE - 1 ? true : false; //checks if it is greater then the size allocated
}

template <class A>
void ArrayStack<A>::clear() {

    m_top = 0;	//goes back to the top
}

template <class A>
void ArrayStack<A>::serialize(std::ostream &os) const {

    for(size_t i = 0; i <= m_top ; i++){	//runs for size of object

        os << m_container[i];	//prints out what was in the container
    }

    os << endl;
}


template <class A>
std::ostream&operator<<(std::ostream& os,  const ArrayStack<A>& arrayStack) {

    arrayStack.serialize(os);	//calls serialize because it's not member function
    return os;

}


