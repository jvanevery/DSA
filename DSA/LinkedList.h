// Header file for an API for a singly linked list
#pragma once

namespace LL {

	//Singly linked list node
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

	//Singly linked list
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
		bool contains(T data);
		size_t sizeOf();
		void print();
	};

	//IMPLEMENTATION

	template<class T>
	SLLNode<T>::SLLNode() {
		ptr_next = nullptr;
	}

	template <class T>
	SLList<T>::SLList() {
		ptr_head = nullptr;
		ptr_tail = nullptr;
	}

	//Insert node at the head of the list
	template <class T>
	void SLList<T>::insertAtHead(T newData) {
		SLLNode<T>* ptr_newNode = new SLLNode<T>();
		ptr_newNode->data = newData;
		if (ptr_head != nullptr) {
			ptr_newNode->ptr_next = ptr_head;
			ptr_head = ptr_newNode;
		}
		else {
			ptr_head = ptr_newNode;
			ptr_tail = ptr_newNode;
		}
		size++;
	}

	//Insert node at the tail of the list
	template <class T>
	void SLList<T>::insertAtTail(T newData) {
		SLLNode<T>* ptr_newNode = new SLLNode<T>();
		ptr_newNode->data = newData;
		ptr_newNode->ptr_next = nullptr;
		if (ptr_tail != nullptr) {
			ptr_tail->ptr_next = ptr_newNode;
			ptr_tail = ptr_newNode;
		}
		else {
			ptr_tail = ptr_newNode;
			ptr_head = ptr_newNode;
		}
		++size;
	}

	//Return head
	template <class T>
	T SLList<T>::peekAtHead() {
		return ptr_head->data;
	}

	//Return tail
	template <class T>
	T SLList<T>::peekAtTail() {
		return ptr_tail->data;
	}

	//Delete node at the head of the list if possible
	template <class T>
	void SLList<T>::deleteAtHead() {
		if (ptr_head != nullptr) {
			SLLNode<T>* ptr_temp = ptr_head;
			//Check for the single node case
			if (ptr_head != ptr_tail) {
				ptr_head = ptr_head->ptr_next;
			}
			else {
				ptr_head = nullptr;
				ptr_tail = nullptr;
			}
			delete ptr_temp;
			--size;
		}
	}

	//Delete node at the tail of the list if possible
	template <class T>
	void SLList<T>::deleteAtTail() {
		if (ptr_tail != nullptr) {
			SLLNode<T>* ptr_temp = ptr_head;
			//check for single node case
			if (ptr_head != ptr_tail) {
				//search for node that points to the tail
				while (ptr_temp->ptr_next != ptr_tail) {
					ptr_temp = ptr_temp->ptr_next;
				}
				delete ptr_temp->ptr_next;
				ptr_temp->ptr_next = nullptr;
				ptr_tail = ptr_temp;
			}
			else {
				delete ptr_temp;
				ptr_head = nullptr;
				ptr_tail = nullptr;
			}
			--size;
		}
	}

	//Returns true if the list contains a node with data equivalent to T, false otherwise
	template <class T>
	bool SLList<T>::contains(T data) {
		SLLNode<T>* ptr_temp = ptr_head;
		bool isContained = false;
		while (ptr_temp != nullptr) {
			if (ptr_temp->data == data) {
				isContained = true;
				break;
			}
			ptr_temp = ptr_temp->ptr_next;
		}
		return isContained;
	}

	//Return size of list
	template <class T>
	size_t SLList<T>::sizeOf() {
		return size;
	}

	//Print text representation of the SLL.
	//Must overload << operator in class T to use this method.
	template <class T>
	void SLList<T>::print() {
		if (ptr_head == nullptr) {
			std::cout << "EMPTY" << std::endl;
		}
		else {
			SLLNode<T>* ptr_temp = ptr_head;
			while (ptr_temp != nullptr) {
				std::cout << ptr_temp->data << " ";
				ptr_temp = ptr_temp->ptr_next;
			}
			std::cout << std::endl;
		}
	}

}