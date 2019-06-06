//SQD stands for stacks, queues, and deques
//Stack is implemented with a singly linked list
//Queue is implemented with a singly linked list 
//May add dynamic array implementations
//Took an encapsulation approach by using a LinkedList member and defining the allowed operations
//This header is dependent on the LinkedList.h template classes

//TODO::You just slap an interface on a linked list instead of going the encapsulation route.
#pragma once

#include "LinkedList.h"

namespace JVSQD {

	//Stack will only use a select number of operations from SLList. The class pretty much serves
	//as a wrapper to abstract the operations in linked list
	template <class T>
	class Stack {

	private:
		JVLL::SLList<T>* list;

	public:
		Stack();
		~Stack();
		void push(T data);
		T peek();
		void pop();
		bool contains();
		bool isEmpty();
	};

	//Queue will only use a select number of operations from SLList. Again we are abstracting an SLL
	//We'll be inserting elements at the tail and deleting at the head in order to avoid the O(n)
	//tail deletion cost.
	template <class T>
	class Queue {

	private:
		JVLL::SLList<T>* list;

	public:
		Queue();
		~Queue();
		void enqueue(T data);
		T peek();
		void dequeue();
		bool contains();
		bool isEmpty();
	};


	//IMPLEMENTATION

	//Stack functions
	template <class T>
	Stack<T>::Stack() {
		list = new JVLL::SLList<T>();
	}

	template <class T>
	Stack<T>::~Stack() {
		delete list;
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

	//Queue Functions
	template <class T>
	Queue<T>::Queue() {
		list = new JVLL::SLList<T>();
	}

	template <class T>
	Queue<T>::~Queue() {
		delete list;
	}

	template <class T>
	void Queue<T>::enqueue(T data) {
		list->insertAtTail(data);
	}

	template <class T>
	T Queue<T>::peek() {
		return list->peekAtHead();
	}

	template <class T>
	void Queue<T>::dequeue() {
		list->deleteAtHead();
	}

	template <class T>
	bool Queue<T>::contains() {
		return list->contains();
	}

	template <class T>
	bool Queue<T>::isEmpty() {
		if ((list->sizeOf()) == 0) { return true; }
		else { return false; }
	}
}
