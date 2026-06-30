#include "BinarySearchTree.h"
#include <iostream>
#include <string>

int main() {

    // Create new binary seach tree
    BinarySearchTree bst;

    // Add values
    bst.insert(5);
    bst.insert(10);
    bst.insert(3);

    // Display the tree
    bst.display();

    // Search for the values
    std::cout << bst.search(10) << "\n";

    // Remove a value
    bst.remove(10);

    // Display the tree
    bst.display();

    return 0;
}
