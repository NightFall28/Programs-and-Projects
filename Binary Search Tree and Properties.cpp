#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

node* insert(node* root, int key) {
	if (root == NULL) {
		root = new node();
		root->data = key;
		root->left = root->right = NULL;
	}
	else {
		node* current = root;
		while (current != NULL) {
			if (key < current->data) {
				if (current->left == NULL) {
					current->left = new node();
					current->left->data = key;
					current->left->left = current->left->right = NULL;
					current = NULL;
				}
				else {
					current = current->left;
				}
			}
			else {
				if (current->right == NULL) {
					current->right = new node();
					current->right->data = key;
					current->right->left = current->right->right = NULL;
					current = NULL;
				}
				else {
					current = current->right;
				}
			}
		}
	}
	return root;
}

bool search(node* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->data == key)
		return true;
	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

void inorder(node* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int height(node* root) {
	if (root == NULL)
		return -1;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (leftHeight > rightHeight)
		return 1 + leftHeight;
	else
		return 1 + rightHeight;
}

int main() {

	node* root = NULL;
	root = insert(root, 15);
	root = insert(root, 28);
	root = insert(root, 2);
	root = insert(root, -29);
	root = insert(root, 121);

	cout << "Inorder: ";
	inorder(root);
	cout << endl;

	cout << "Preorder: ";
	preorder(root);
	cout << endl;

	cout << "Postorder: ";
	postorder(root);
	cout << endl;

	cout << "Height: " << height(root) << endl;

	int number;
	cout << "Enter a number to search: ";
	cin >> number;
	if (search(root, number))
		cout << number << " is found" << endl;
	else
		cout << number << " is not found\n";


	delete root;

	return 0;
}
