#ifndef HW2_QUEUE_H
#define HW2_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
	int front;
	int rear;
	int size;
	T* array;
	int capacity;
public:
	Queue(int c);
	~Queue();
	bool isEmpty() const;
	T getFront() const;
	T getRear() const;
	int getSize() const;
	int getCapacity() const;
	void push(const T& x);
	T pop();
	void print() const;
	void shift(int amount);
};

template <class T>
Queue<T>::Queue(int c) {
	// TODO
	front = 0;
	rear = 0;
	size = 0;
	array = new int[c];
	capacity = c;
}

template <class T>
Queue<T>::~Queue() {
	// TODO
	delete[] array;
}

template <class T>
bool Queue<T>::isEmpty() const {
	// TODO
	return size == 0;
}

template <class T>
T Queue<T>::getFront() const {
	// TODO
	if (isEmpty()) return T();
	return array[(front + 1) % capacity];
}

template <class T>
T Queue<T>::getRear() const {
	// TODO
	if (isEmpty()) return T();
	return array[rear];
}

template <class T>
int Queue<T>::getSize() const {
	// TODO
	return size;
}

template <class T>
int Queue<T>::getCapacity() const {
	// TODO
	return capacity;
}

template <class T>
void Queue<T>::push(const T& x) {
	// TODO
	if (capacity == size + 1) {
		capacity *= 2;
		int *newArray = new int[capacity];
		for (int i = 0; i <= size; i++) 
			newArray[i + 1] = array[(front + 1 + i) % (size  + 1)];
		delete[] array;
		array = newArray;
		front = 0;
		rear = size;
	}
	rear++;
	while (rear >= capacity) rear -= capacity;
	array[rear] = x;
	size++;
}

template <class T>
T Queue<T>::pop() {
	// TODO
	if (size == 0) return T();
	size--;
	front++;
	while (front >= capacity) front -= capacity;
	return array[front];
}

template <class T>
void Queue<T>::print() const {
	// TODO
	int curr = front + 1;
	cout << '[';
	if (curr >= capacity) curr -= capacity;
	if (size != 0) cout << array[curr];
	while (size != 0 && curr != rear) {
		if (++curr >= capacity) curr -= capacity;
		cout << ", " << array[curr];
	}
	cout << ']' << endl;
}

template <class T>
void Queue<T>::shift(int amount) {
	// TODO
	int* newArray = new int[capacity];
	for (int i = front; i != rear; ) {
		if (++i == capacity) i = 0;
		int idx = i + amount;
		while (idx <= 0) idx += size;
		while (idx > size) idx -= size;
		newArray[idx] = array[i];
	}
	delete array;
	front = 0;
	rear = size;
	array = newArray;
}

#endif
