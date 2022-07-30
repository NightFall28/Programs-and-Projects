#include <iostream>
using namespace std;

//Binary Tree node
struct BTnode {
    int data;
    BTnode* left;
    BTnode* right;
};

BTnode* CreateNewNode(int data)
{
    BTnode* newNode = new BTnode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BTnode* insert(BTnode* root, int data)
{
    if (root == NULL) // if tree is empty
        root = CreateNewNode(data);
    else if (data <= root->data) {
        root->left = insert(root->left, data);

    }
    else
        root->right = insert(root->right, data);
    return root;
}

bool search(BTnode* root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main()
{
    BTnode* root = NULL; // create an empty tree
    root = insert(root, 15); root = insert(root, 20); root = insert(root, 25); root = insert(root, 64); root = insert(root, 28);
    int number;
    cout << "Enter a number to be searched: \n";
    cin >> number;
    if (search(root, number))
        cout << "Found\n";
    else
        cout << "Not Found\n";

}

