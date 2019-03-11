// Header file for an API for singly and doubly linked lists
#pragma once

namespace LL {

	template <class T>
	class SLLNode {

	protected:
		T data;
		SLLNode* ptr_next;

	public:
		SLLNode();
		
		//Giving SLList access to SLLNode as an alternative to nesting the classes
		template <class U>
		friend class SLList;
	};

	template <class T>
	class SLList {

	protected:
		SLLNode<T>* ptr_head;
		SLLNode<T>* ptr_tail;
		size_t size;

	public:
		SLList();
		void insertAtHead(T newData);
		void insertAtTail(T newData);
		void deleteAtHead();
		void deleteAtTail();
		T peekAtHead();
		T peekAtTail();
		void print();
		//T getDataAt(int i);
		//T& remove(int index);
		//addLast(T& elem);
	};

	////////////////////////////
	/******IMPLEMENTATION******/
	////////////////////////////

	template<class T>
	SLLNode<T>::SLLNode() {
		ptr_next = nullptr;
	}

	template <class T>
	SLList<T>::SLList() {
		ptr_head = nullptr;
		ptr_tail = nullptr;
	}

	template <class T>
	void SLList<T>::insertAtHead(T newData) {
		SLLNode<T>* ptr_newNode = new SLLNode<T>();
		ptr_newNode->ptr_next = ptr_head;
		ptr_newNode->data = newData;
		ptr_head = ptr_newNode;
		if (ptr_tail == nullptr) {
			ptr_tail = ptr_newNode;
		}
		size++;
	}

	template <class T>
	void SLList<T>::insertAtTail(T newData) {
		SLLNode<T>* ptr_newNode = new SLLNode<T>();
		ptr_newNode->ptr_next = nullptr;
		ptr_newNode->data = newData;
		ptr_tail->ptr_next = ptr_newNode;
		ptr_tail = ptr_newNode;
		if (ptr_head == nullptr) {
			ptr_head = ptr_newNode;
		}
		++size;
	}

	template <class T>
	T SLList<T>::peekAtHead() {
		return ptr_head->data;
	}

	template <class T>
	T SLList<T>::peekAtTail() {
		return ptr_tail->data;
	}

	template <class T>
	void SLList<T>::deleteAtHead() {
		if (ptr_head != nullptr) {
			SLLNode<T>* ptr_temp = ptr_head->ptr_next;
			delete ptr_head;  //deallocate node at old head
			ptr_head = ptr_temp;
			--size;
		}
	}

	template <class T>
	void SLList<T>::deleteAtTail() {
		
	}

	template <class T>
	void SLList<T>::print() {
		if (ptr_head == nullptr) {
			std::cout << "EMPTY" << std::endl;
		}
		else {
			//Must overload << operator in class T to use this method
			SLLNode<T>* ptr_temp = ptr_head;
			while (ptr_temp != nullptr) {
				std::cout << ptr_temp->data << " ";
				ptr_temp = ptr_temp->ptr_next;
			}
			std::cout << std::endl;
		}
	}

}