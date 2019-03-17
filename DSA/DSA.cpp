/**
	DSA.cpp : Defines the entry point for the console application.

	Here we will be testing the functionality of a bunch of different data structures and 
	algorithms that I will be developing for learning/practice.
**/

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"

using namespace LL;
using namespace std;

int main()
{
	//Create a singly linked list and add some elements
	SLList<int> sllTest = SLList<int>();
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

    return 0;
}

