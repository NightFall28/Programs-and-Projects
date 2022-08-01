#include "hash.h"
using namespace std;


int main() {
	HashTable hash = HashTable(10);
	srand(time(0));
	for (int i = 0; i < 20; i++) {
		hash.insert(rand() % 100);
	}

	hash.print();

	return 0;
}
