//Use singly linked list to implement a stack. Supports push, pop, peek, contains, and isEmpty operations
//Is dependent on the LinkedList.h template classes
#pragma once

#include "LinkedList.h"

namespace JVStack {

	//Stack will only use a select number of operations from SLList. The class pretty mich serves
	//as a wrapper to abstract the operations in linked list
	template <class T>
	class Stack {

	private:
		JVLL::SLList<T>* list;

	public:
		Stack();
		void push(T data);
		T peek();
		void pop();
		bool contains();
		bool isEmpty();
	};


	//IMPLEMENTATION
	template <class T>
	Stack<T>::Stack() {
		list = new SLList<T>();
	}

	template <class T>
	void Stack<T>::push(T data) {
		list->insertAtHead(data);
	}

	template <class T>
	T Stack<T>::peek() {
		return list->peekAtHead();
	}

	template <class T>
	void Stack<T>::pop() {
		list->deleteAtHead();
	}

	template <class T>
	bool Stack<T>::contains() {
		return list->contains();
	}

	template <class T>
	bool Stack<T>::isEmpty() {
		if ((list->sizeOf()) == 0) { return true; }
		else { return false; }
	}

}
