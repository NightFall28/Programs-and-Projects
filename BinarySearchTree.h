#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

class BinarySearchTree {
private:
    Node* root;

    void DeleteTree(Node* treeRoot) {
        if (treeRoot)
        {
            DeleteTree(treeRoot->left);
            DeleteTree(treeRoot->right);
            delete treeRoot;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    virtual ~BinarySearchTree() {
        DeleteTree(root);
    }

    Node* GetRoot() {
        return root;
    }

    Node* Search(int desiredKey) {
        Node* currentNode = root;
        while (currentNode) {
            // Return the node if the key matches
            if (currentNode->key == desiredKey) {
                return currentNode;
            }

            // Navigate to the left if the search key is 
            // less than the node's key.
            else if (desiredKey < currentNode->key) {
                currentNode = currentNode->left;
            }

            // Navigate to the right if the search key is 
            // greater than the node's key.
            else {
                currentNode = currentNode->right;
            }
        }

        // The key was not found in the tree.
        return nullptr;
    }

    void Insert(Node* newNode) {
        // Check if tree is empty
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* currentNode = root;
            while (currentNode) {
                if (newNode->key < currentNode->key) {
                    // If no left child exists, add the new node
                    // here; otherwise repeat from the left child.
                    if (currentNode->left == nullptr) {
                        currentNode->left = newNode;
                        currentNode = nullptr;
                    }
                    else {
                        currentNode = currentNode->left;
                    }
                }
                else {
                    // If no right child exists, add the new node
                    // here; otherwise repeat from the right child.
                    if (currentNode->right == nullptr) {
                        currentNode->right = newNode;
                        currentNode = nullptr;
                    }
                    else {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

    bool Remove(int key) {
        Node* parent = nullptr;
        Node* currentNode = root;

        // Search for the node.
        while (currentNode) {
            // Check if currentNode has a matching key.
            if (currentNode->key == key) {
                if (currentNode->left == nullptr && currentNode->right == nullptr) { // Case 1
                    if (parent == nullptr) { // Node is root
                        root = nullptr;
                    }
                    else if (parent->left == currentNode) {
                        parent->left = nullptr;
                    }
                    else {
                        parent->right = nullptr;
                    }
                    delete currentNode;
                    return true; // Node found and removed
                }
                else if (currentNode->left && currentNode->right == nullptr) { // Case 2
                    if (parent == nullptr) { // Node is root
                        root = currentNode->left;
                    }
                    else if (parent->left == currentNode) {
                        parent->left = currentNode->left;
                    }
                    else {
                        parent->right = currentNode->left;
                    }
                    delete currentNode;
                    return true; // Node found and removed
                }
                else if (currentNode->left == nullptr && currentNode->right) { // Case 2
                    if (parent == nullptr) { // Node is root
                        root = currentNode->right;
                    }
                    else if (parent->left == currentNode) {
                        parent->left = currentNode->right;
                    }
                    else {
                        parent->right = currentNode->right;
                    }
                    delete currentNode;
                    return true; // Node found and removed
                }
                else { // Case 3
                   // Find successor (leftmost child of right subtree)
                    Node* successor = currentNode->right;
                    while (successor->left) {
                        successor = successor->left;
                    }
                    currentNode->key = successor->key; // Copy successor's key to current node
                    parent = currentNode;

                    // Reassigned currentNode and key so that loop continues with new key
                    currentNode = currentNode->right;
                    key = successor->key;
                }
            }
            else if (currentNode->key < key) { // Search right
                parent = currentNode;
                currentNode = currentNode->right;
            }
            else { // Search left
                parent = currentNode;
                currentNode = currentNode->left;
            }
        }
        return false; // Node not found
    }
};

#endif