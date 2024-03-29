/**
	DSA.cpp : Defines the entry point for the console application.

	Here we will be testing the functionality of a bunch of different data structures and 
	algorithms that I will be developing for learning/practice.
**/

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
#include "SQD.h"
#include <string>

using namespace JVLL;
using namespace JVSQD;
using namespace std;

int main()
{
	//Create a singly linked list and add some elements
	SLList<int> sllTest = SLList<int>();
	std::cout << "Starting clumsy SLL test..." << std::endl;
	sllTest.print();
	sllTest.insertAtHead(1);
	sllTest.insertAtHead(5);
	sllTest.insertAtHead(2);
	sllTest.insertAtTail(0);
	sllTest.insertAtTail(9);
	sllTest.insertAtHead(10);
	//Expected print output 10 2 5 1 0 9
	sllTest.print();
	//Expected print output 10
	std::cout << sllTest.peekAtHead() << std::endl;
	//Expected print output 9
	std::cout << sllTest.peekAtTail() << std::endl;
	//Do some deletion at head
	sllTest.deleteAtHead();
	sllTest.deleteAtHead();
	//Expected print output 5 1 0 9
	sllTest.print();
	//Test contains()
	std::cout << sllTest.contains(5) << std::endl;
	std::cout << sllTest.contains(9) << std::endl;
	std::cout << sllTest.contains(1) << std::endl;
	std::cout << sllTest.contains(10) << std::endl;
	//Check size=4
	std::cout << sllTest.sizeOf() << std::endl;
	//Do some deletion at tail
	sllTest.deleteAtTail();
	sllTest.deleteAtTail();
	sllTest.print();
	//Test edge case for deletion at tail
	sllTest.deleteAtTail();
	sllTest.deleteAtTail();
	sllTest.deleteAtTail();
	sllTest.print();
	//check edge case for insertion at tail
	sllTest.insertAtTail(7);
	sllTest.print();
	//check edge case for deletion at head
	sllTest.deleteAtHead();
	sllTest.print();
	//Check size=0
	std::cout << sllTest.sizeOf() << std::endl;

	//Create a doubly linked list and add some elements
	DLList<int> dllTest = DLList<int>();
	std::cout << "Starting clumsy DLL test..." << std::endl;
	dllTest.print();
	dllTest.insertAtHead(5);
	dllTest.insertAtHead(6);
	dllTest.insertAtHead(7);
	dllTest.insertAtTail(11);
	dllTest.insertAtTail(10);
	dllTest.insertAtHead(3);
	dllTest.print(); //3 7 6 5 11 10
	std::cout << dllTest.peekAtHead() << std::endl; //3
	std::cout << dllTest.peekAtTail() << std::endl; //10
	//Do some deletion at head
	dllTest.deleteAtHead();
	dllTest.deleteAtHead();  
	dllTest.print();	//6 5 11 10 
	//Test contains()
	std::cout << dllTest.contains(6) << std::endl;	//1
	std::cout << dllTest.contains(5) << std::endl;	//1
	std::cout << dllTest.contains(10) << std::endl;	//1
	std::cout << dllTest.contains(7) << std::endl;	//0
	//Check size
	std::cout << dllTest.sizeOf() << std::endl; //4
	//Do some deletion at tail
	dllTest.deleteAtTail();
	dllTest.deleteAtTail();
	dllTest.print();	//6 5
	//Test edge case for deletion at tail
	dllTest.deleteAtTail();
	dllTest.deleteAtTail();
	dllTest.deleteAtTail();
	dllTest.print();	//EMPTY
	//check edge case for insertion at tail
	dllTest.insertAtTail(7);
	dllTest.print();	//7
	//check edge case for deletion at head
	dllTest.deleteAtHead();
	dllTest.print();	//EMPTY
	//Check size
	std::cout << dllTest.sizeOf() << std::endl; //0

	//Messing around with stack
	std::cout << "Starting crude Stack test..." << std::endl;
	JVSQD::Stack<string> stringStack;
	stringStack.push("lives");
	stringStack.push("lived");
	stringStack.push("will live");
	stringStack.push("dies");
	stringStack.push("died");
	stringStack.push("will die");
	//peek and pop until empty
	while (!stringStack.isEmpty()) {
		std::cout << stringStack.peek() << std::endl;
		stringStack.pop();
	}
	//Verify that it is empty
	std::cout << stringStack.isEmpty() << std::endl; //1
	//Pop again and check again
	stringStack.pop();
	std::cout << stringStack.isEmpty() << std::endl; //1

	//Messing around with queue
	std::cout << "Starting crude Queue test...I need to make unit tests..." << std::endl;
	//TODO: Make some unit tests for practice!
	JVSQD::Queue<string> stringQueue;
	stringQueue.enqueue("vita");
	stringQueue.enqueue("est");
	stringQueue.enqueue("morte");
	stringQueue.enqueue("est");
	stringQueue.enqueue("vita");
	stringQueue.enqueue("!");
	//Start deque-ing
	while (!stringQueue.isEmpty()) {
		std::cout << stringQueue.peek() << std::endl;
		stringQueue.dequeue();
	}

    return 0;
}

