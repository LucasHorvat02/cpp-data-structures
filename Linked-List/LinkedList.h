#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @brief Represents a single element (node) in the singly linked list.
 */
struct Node { 
    int data;       // The value stored in the node 
    Node* next;     // Pointer to the next node in the list

    /**
     * @brief Constructor to initialize a node with data.
     * @param val The integer value to store in the node.
     */
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/**
 * @brief A custom implementation of a Singly Linked List managing dynamic memory.
 */
class LinkedList {

    private:
        Node* head;         // Pointer to the first node in the list
        int length = 0;     // Tracks the total number of elements in the list

    public:
        LinkedList();       // Intializes the empty list
        ~LinkedList();      // Cleans up allocated memory to prevent memory leaks

        // -------- Mutators -------- // 

        /**
         * @brief Appends a new value to the very end of the list.
         * @param val The integer to be added.
         */
        void add(int val);

        /**
         * @brief Inserts a new value at a specific position.
         * @param index The target position (0-indexed).
         * @param val The integer to be inserted.
         * @note Prints an error and returns if index is out of bounds.
         */
        void add(int index, int val);

        /**
         * @brief Removes the first occurrence of a value from the list.
         * @param val The integer value to find and delete.
         */
        void remove(int val);

        // ------- Accessors & Utilities ------- //

        /**
         * @brief Prints the entire list to the console (e.g., 10 -> 20 -> nullptr).
         */
        void display() const;

        /**
         * @brief Gets the current number of elements in the list.
         * @return The size of the list as an integer.
         */
        int size() const;

};

#endif
