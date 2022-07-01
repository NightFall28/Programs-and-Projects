#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "BinarySearchTree.h"
#include "BSTPrint.h"
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
	BinarySearchTree tree;

	cout << "Enter values to insert with spaces between: ";
	string userValueString;
	getline(cin, userValueString);
	cout << endl;

	vector<string> userValues;
	SpaceSplit(userValueString, userValues);
	for (string value : userValues) {
		int key = stoi(value);
		tree.Insert(new Node(key));
	}

	cout << "Inital tree:" << endl;
	cout << BSTPrint::TreeToString(tree.GetRoot()) << endl;
	cout << endl;

	cout << "Enter a value to remove: ";
	string removeValueString;
	getline(cin, removeValueString);
	int removeValue = stoi(removeValueString);
	cout << endl;

	cout << "Tree after removing " << removeValue << ":" << endl;
	tree.Remove(removeValue);
	cout << BSTPrint::TreeToString(tree.GetRoot()) << endl;


}
