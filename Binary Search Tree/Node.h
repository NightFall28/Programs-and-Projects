#ifndef NODE_H
#define NODE_H

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int nodeKey) {
		key = nodeKey;
		left = nullptr;
		right = nullptr;
	}
};

#endif
