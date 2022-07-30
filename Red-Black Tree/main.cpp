#include <iostream>
#include <string>
#include <vector>
#include "RBT.h"
#include "RBTPrint.h"
using namespace std;

void SpaceSplit(const string& str, vector<string>& output)
{
	size_t startIndex = 0;
	size_t endIndex = str.find(' ', startIndex);
	while (endIndex != string::npos) {
		if (endIndex > startIndex) {
			output.push_back(str.substr(startIndex, endIndex - startIndex));
		}
		startIndex = endIndex + 1;
		endIndex = str.find(' ', startIndex);
	}
	output.push_back(str.substr(startIndex));
}

int main() {
	cout << "Enter insert value: ";
	string userValueStr;
	getline(cin, userValueStr);
	cout << endl;

	vector<string> userValues;
	SpaceSplit(userValueStr, userValues);

	RedBlackTree tree;
	for (string value : userValues) {
		tree.Insert(stoi(value));
	}

	cout << "Red-Black tree with " << tree.GetLength();
	cout << " nodes has height " << tree.GetHeight() << endl;
	cout << RBTPrint::TreeToString(tree.GetRoot()) << endl;

	cout << "Enter remove values: ";
	getline(cin, userValueStr);
	cout << endl;

	userValues.clear();
	SpaceSplit(userValueStr, userValues);

	for (string value : userValues) {
		int toRemove = stoi(value);
		cout << "Remove node " << value << ": ";
		if (tree.Remove(toRemove)) {
			cout << "Red-Black tree with " << tree.GetLength();
			cout << "nodes has height " << tree.GetHeight() << endl;
		}
		else {
			cout << "Key not found. Tree is not changed." << endl;
		}
	}

	cout << RBTPrint::TreeToString(tree.GetRoot()) << endl;

	return 0;
}
