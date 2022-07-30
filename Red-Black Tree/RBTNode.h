#ifndef RBTNODE_H
#define RBTNODE_H

class RBTNode {
public:
    enum Child { LEFTCHILD, RIGHTCHILD };

    enum Color { REDCOLOR, BLACKCOLOR };

    int key;
    RBTNode* parent;
    RBTNode* left;
    RBTNode* right;
    Color color;

    RBTNode(int nodeKey, RBTNode* parentNode, bool isRed,
        RBTNode* leftChild = nullptr, RBTNode* rightChild = nullptr) {
        key = nodeKey;
        parent = parentNode;
        left = leftChild;
        right = rightChild;
        color = isRed ? Color::REDCOLOR : Color::BLACKCOLOR;
    }

    // Returns true if both child nodes are black. A child set to None is considered
    // to be black.
    bool AreBothChildrenBlack() {
        if (left && left->IsRed()) {
            return false;
        }
        if (right && right->IsRed()) {
            return false;
        }
        return true;
    }

    int Count() {
        int count = 1;
        if (left) {
            count += left->Count();
        }
        if (right) {
            count += right->Count();
        }
        return count;
    }

    RBTNode* GetGrandparent() {
        if (parent == nullptr) {
            return nullptr;
        }
        return parent->parent;
    }

    // Gets this node's predecessor from the left child subtree
    // Precondition: This node's left child is not null
    RBTNode* GetPredecessor() {
        RBTNode* node = left;
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    // Returns this node's sibling, or null if this node does not have a sibling
    RBTNode* GetSibling() {
        if (parent) {
            if (this == parent->left) {
                return parent->right;
            }
            return parent->left;
        }
        return nullptr;
    }

    // Returns the uncle of this node
    RBTNode* GetUncle() {
        RBTNode* grandparent = GetGrandparent();
        if (grandparent == nullptr) {
            return nullptr;
        }
        if (grandparent->left == parent) {
            return grandparent->right;
        }
        return grandparent->left;
    }

    // Returns true if this node is black, false otherwise
    bool IsBlack() {
        return color == Color::BLACKCOLOR;
    }

    // Returns true if this node is red, false otherwise
    bool IsRed() {
        return color == Color::REDCOLOR;
    }

    // Replaces one of this node's children with a new child
    bool ReplaceChild(RBTNode* currentChild, RBTNode* newChild) {
        if (left == currentChild) {
            return SetChild(Child::LEFTCHILD, newChild);
        }
        else if (right == currentChild) {
            return SetChild(Child::RIGHTCHILD, newChild);
        }
        return false;
    }

    // Sets either the left or right child of this node
    bool SetChild(Child whichChild, RBTNode* child) {
        if (whichChild == Child::LEFTCHILD) {
            left = child;
        }
        else {
            right = child;
        }

        if (child) {
            child->parent = this;
        }

        return true;
    }
};

#endif
