#ifndef HW2_STACK_H
#define HW2_STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
	class Node {
	private:
		Node* next;
		T data;

	public:
		Node(T d) {
			data = d;
		}
		Node(T d, Node* n) {
			data = d;
			next = n;
		}
		void setNext(Node* n) {
			next = n;
		}
		Node* getNext() {
			return next;
		}
		T getData() {
			return data;
		}
	};

private:
	Node* top;
	int size;

public:
	Stack();
	~Stack();
	bool isEmpty() const;
	T getTop() const;
	int getSize() const;
	void push(const T&);
	T pop();
	void print() const;

};

template <class T>
Stack<T>::Stack() {
	// TODO
	top = null;
	size = 0;
}

template <class T>
Stack<T>::~Stack() {
	// TODO
	while (top != null) {
		node* temp = top->next;
		delete top;
		top = temp;
	}
}

template <class T>
bool Stack<T>::isEmpty() const {
	// TODO
	return size == 0;
}

template <class T>
T Stack<T>::getTop() const {
	// TODO
	return (*top);
}

template <class T>
int Stack<T>::getSize() const {
	// TODO
	return size;
}

template <class T>
void Stack<T>::push(const T& newData) {
	// TODO
	node* newNode(newData);
	newNode->next = top;
	top = newNode;
}

template <class T>
T Stack<T>::pop() {
	// TODO
	T data = top->data;
	node* delNode = top;
	top = top->next;
	delete delNode;
	return data;
}

template <class T>
void Stack<T>::print() const {
	// TODO
	node* curr = top;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
}

#endif