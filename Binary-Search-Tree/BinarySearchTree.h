#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

/**
 * @brief Represents a single node in the Binary Search Tree.
 */
struct TreeNode {

    int data;           // The integer value stored in the node
    TreeNode* left;     // Pointer to the left child node
    TreeNode* right;    // Pointer to the right child node

    /**
     * @brief Constructor to initialize a node with a value.
     * @param val The integer value to store in the node.
     */
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @brief A standard unique-integer Binary Search Tree (BST).
 * @details Supports basic CRUD operations: insertion, searching, and deletion.
 * Duplicate values are routed to the left subtree.
 */
class BinarySearchTree {

    private:
        TreeNode* root;     // Root node of the tree

        // ------ Private Recursive Helpers ------ //
        
        /**
         * @brief Recursively deletes all nodes in the tree to free memory.
         * @param current The current node being traversed.
         */
        void clearTree(TreeNode* current);

        /**
         * @brief Helper to print the tree in sorted order (Left, Root, Right).
         * @param current The current node being traversed.
         */
        void inOrderHelper(TreeNode* current) const;

        /**
         * @brief Helper to recursively search for a key.
         * @param current The current node being checked.
         * @param key The value to search for.
         * @return true if found, false otherwise.
         */
        bool find(TreeNode* current, int key);

        /**
         * @brief Helper to recursively find and delete a node.
         * @param current The current node being checked.
         * @param val The value to remove from the tree.
         * @return TreeNode* The updated child pointer for the parent node.
         */
        TreeNode* removeHelper(TreeNode* current, int val);

        /**
         * @brief Helper to find the node with the minimum value in a subtree.
         * @param current The root of the subtree to search.
         * @return TreeNode* Pointer to the node with the minimum value.
         */
        TreeNode* findMin(TreeNode* current) const;


    public:

        /**
         * @brief Default constructor. Initializes an empty tree.
         */
        BinarySearchTree();

        /**
         * @brief Destructor. Safely frees all memory allocated by the tree.
         */
        ~BinarySearchTree();

        /**
         * @brief Inserts a new value into the Binary Search Tree.
         * @param val The integer value to insert.
         */
        void insert(int val);

        /**
         * @brief Prints the contents of the tree to the console in ascending order.
         */
        void display() const;

        /**
         * @brief Searches the tree for a specific key.
         * @param key The integer value to look for.
         * @return true if the key exists in the tree, false otherwise.
         */
        bool search(int key);

        /**
         * @brief Removes a value from the tree if it exists.
         * @param key The integer value to delete.
         */
        void remove(int key);

};

#endif
