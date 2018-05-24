#ifndef HW3_HASH_H
#define HW3_HASH_H

#include <iostream>
using namespace std;

template <class V>

class HashTable {
private:
	template <class V>
	class HashNode {
	public:
		int key;
		V value;
		HashNode(int key_, V value_) {
			key = key_;
			value = value_;
		}
	};
	HashNode<V> **table;
	int capacity;
	int number;
	HashNode<V> *dummy;

public:
	HashTable(int cap);
	~HashTable();
	void tableDoubling();
	int hashFunction(int key) {
		return key % capacity;
	}
	void insertNode(int key, V value);
	V deleteNode(int key);
	V search(int key);
	void display();
};

template <class V>
HashTable<V>::HashTable(int cap) {
	// TODO
	capacity = cap;
	number = 0;
	dummy = new HashNode<V>(-1, NULL);
	table = new (HashNode<V>*);
	for (int i = 0; i < capacity; i++)
		table[i] = NULL;
}

template <class V>
HashTable<V>::~HashTable() {
	// TODO
	delete dummy;
	delete[] table;
}

template <class V>
void HashTable<V>::tableDoubling() {
	// TODO
	capacity *= 2;
	HashNode<V> **newTable = new (HashNode<V>*);
	for (int i = 0; i < capacity; i++)
		newTable[i] = NULL;

	for (int i = 0; i < capacity / 2; i++) {
		if (table[i] == NULL) continue;
		int address = hashFunction(table[i]->key);
		while (newTable[address] != NULL)
			address++;
		newTable[address] = new HashNode<V>(table[i]->key, table[i]->value);
	}
	for (int i = 0; i < capacity / 2; i++)
		delete table[i];
	table = newTable;
}

template <class V>
void HashTable<V>::insertNode(int key, V value) {
	// TODO
	int address = hashFunction(key);
	while (table[address] != NULL)
		address++;
	table[address] = new HashNode<V>(key, value);
	number++;
	if (number * 2 > capacity)
		tableDoubling();
}

template <class V>
V HashTable<V>::deleteNode(int key) {
	// TODO
	int address = hashFunction(key);
	while (table[address] != NULL && table[address]->key != key) {
		address++;
		if (address == capacity - 1) address = 0;
	}
	if (table[address] == NULL) {
		cout << "not exist" << endl;
		return NULL;
	}
	V ret = table[address]->value;
	delete table[address];
	table[address] = dummy;
	return ret;
}

template <class V>
V HashTable<V>::search(int key) {
	//TODO
	int address = hashFunction(key);
	while (table[address] != NULL && table[address]->key != key) {
		address++;
	}
	return table[address]->value;
}


template <class V>
void HashTable<V>::display() {
	//TODO
	cout << capacity << ' ' << number << endl;
	for (int i = 0; i < capacity; i++) {
		if (table[i] == NULL) continue;
		if (table[i]->key == -1) continue;
		cout << i << ' ' << table[i]->key << ' ' << table[i]->value << endl;
	}
}

#endif
