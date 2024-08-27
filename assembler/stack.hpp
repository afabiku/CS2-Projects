//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include <iostream>
#include "../string/string.hpp"
#include <vector>

template<typename T> 
class Node {
public:
	Node();
	Node(T i);
	T Data;
	Node<T> * next;
};


// CLASS INV:
//
template <typename T>
class stack {
public:
    stack();
    stack(const stack<T>&);

    ~stack();
	
	void swap(stack<T>& input);

	stack<T>&operator=(stack<T> input);

	bool empty() const;
	bool full() const;
	T top() const;
	T pop();
	void push(const T&input);

private:
	Node<T>   *tos;
};


template<typename T>
Node<T>::Node():Data(0), next(0) {};

template<typename T>
Node<T>::Node(T i):Data(i), next(0) {};

template<typename T>
stack<T>::stack(){
    tos = 0;
}

template<typename T>
stack<T>::stack(const stack<T>& input){
    tos = 0;
    Node<T> * current = input.tos;
    Node<T> * bottom;
    while(current){
        if(tos == 0){
            tos = new Node<T>(current->Data);
            bottom = tos;
        }else{
            bottom->next=new Node<T>(current->Data);
            bottom = bottom->next;
        }
        current = current->next;
    }
}

template<typename T>
stack<T>::~stack(){
    while(!empty()){
		pop();
	}
}

template<typename T>
void stack<T>::swap(stack<T>& input){
    Node<T> *temp = input.tos;
    input.tos = tos;
    tos =temp;
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> input){
    swap(input);
    return *this;
} 

template<typename T>
bool stack<T>::empty() const{
    return (tos == 0);
};

template<typename T>
bool stack<T>::full() const{
	return false;
}

template<typename T>
T stack<T>::top() const{
	assert(!empty());
	return tos->Data;
};

template<typename T>
T stack<T>::pop(){
    assert(!empty());
    Node<T> * temp = tos;
    T value = temp->Data;
    tos = temp->next;
    delete temp;
    return value;
}

template<typename T>
void stack<T>::push(const T&input){
    assert(!full());
    Node<T> * temp = tos;
    tos = new Node<T>(input);
    tos->next = temp;
}



#endif

