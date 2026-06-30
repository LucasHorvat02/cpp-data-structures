#include "BinarySearchTree.h"
#include <iostream>

// Constructor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    clearTree(root);
}

// Private helper to recursvely delete nodes
void BinarySearchTree::clearTree(TreeNode* current) {
    
    if (current == nullptr) {
        return;
    }

    clearTree(current->left);
    clearTree(current->right);
    delete current;
}

void BinarySearchTree::insert(int val) {

    TreeNode* newTreeNode = new TreeNode(val);

    // If the tree is empty, insert new node at the root
    if (root == nullptr) {
        root = newTreeNode;
        return;
    }

    TreeNode* current = root;

    // Iterate through the tree
    while (current != nullptr) {
        // If new node value > current node value, go to right child
        if (val > current->data) {
            // If there is a right child, traverse the right subtree
            if (current->right != nullptr) {
                current = current->right;
            }
            // Otherwise, insert the new node as the right child
            else {
                current->right = newTreeNode;
                return;
            }
        }
        // If new node value is <= current node value, go to left child
        else {
            // If there is a left child, traverse the left subtree
            if (current->left != nullptr) {
                current = current->left;
            }
            // Otherwise, insert the new node as the left child
            else {
                current->left = newTreeNode;
                return;
            }
        }
    }
}

// Public display function
void BinarySearchTree::display() const{
    inOrderHelper(root);    // Inorder traversal of the tree
    std::cout << "\n";
}


// Private Inorder traversal of the tree
void BinarySearchTree::inOrderHelper(TreeNode* current) const {

    // Return if null ptr
    if (current == nullptr) {
        return;
    }

    inOrderHelper(current->left);           // Traverse left subtree
    std::cout << current->data << " ";      // Print the data
    inOrderHelper(current->right);          // Traverse the right subtree
}

// Public search function
bool BinarySearchTree::search(int key) {
    return find(root, key);
}

// Private find function
bool BinarySearchTree::find(TreeNode* current, int key) {

    // Return false if key is not found
    if (current == nullptr) {
        return false;
    }

    // return true if key is found
    if (key == current->data){
        return true;
    }

    // Traverse right subtree if key > data
    if (key > current->data) {
        return find(current->right, key);
    }
    // Traverse left subtree if key < data
    else {
        return find(current->left, key);
    }

}

// Public remove method
void BinarySearchTree::remove(int key) {
    root = removeHelper(root, key);
}


// Private remove helper
TreeNode* BinarySearchTree::removeHelper(TreeNode* current, int key) {
    
    // Base Case: Value is not in the tree
    if (current == nullptr) {
        return nullptr;
    }

    // Find the target node //
    // Traverse left subtree
    if (key < current->data) {
        current->left = removeHelper(current->left, key);
    }
    // Traverse right subtree
    else if (key > current->data) {
        current->right = removeHelper(current->right, key);
    }
    // Delete the target node after it is found
    // One child or no child
    else {
        if (current->left == nullptr) {
            TreeNode* temp = current->right;
            delete current;
            return temp;    // Returns right child attached to parent
        }
        else if (current->right == nullptr) {
            TreeNode* temp = current->left;
            delete current;
            return temp;    // Returns left child attached to parent
        }

        // Two children
        // Find the smallest node in the right subtree
        TreeNode* temp = findMin(current->right);

        // Replace current node's data with the successor's data
        current->data = temp->data;

        // Recursively delete the duplicate successor node from the right subtree
        current->right = removeHelper(current->right, temp->data);

    }

    return current;

}

// Helper to find the leftmost node
TreeNode* BinarySearchTree::findMin(TreeNode* current) const {
    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}
