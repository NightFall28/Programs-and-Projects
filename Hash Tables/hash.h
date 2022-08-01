#pragma once

#include<iostream>
using namespace std;
#include <list>

class HashTable {
private:
	int buckets;
	list<int>* table;

public:
	HashTable(int number_of_bucket) {
		buckets = number_of_bucket;
		table = new list<int>[buckets];
	}

	void insert(int data) {
		int num_bucket = data % buckets;
		table[num_bucket].push_back(data);
	}

	void print() {
		for (int i = 0; i < buckets; i++) {
			cout << "Bucket " << i << ": ";
			for (auto j : table[i]) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
};
