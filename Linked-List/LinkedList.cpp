#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Deconstructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Add a new node with the value 'val' to the end of the list
void LinkedList::add(int val) {

    // Create the new node
    Node* newNode = new Node(val);

    // If the list is empty, make the head of the list the new node
    if (head == nullptr) {
        head = newNode;
        length++;           // Increment the length
        return;
    }

    // Create temporary pointer to head
    Node* current = head;

    // Iterate to the end of the list
    while (current->next != nullptr) {
        current = current->next;
    }

    // Add the new node to the end of the list
    current->next = newNode;

    // Increment the length of the list
    length++;
}

// Add a new node and a specific index of the list
void LinkedList::add(int index, int val) {

    // If the index is out of bounds, print error
    if (index < 0 || index > length) {
        std::cout << "Index is out of bounds\n";
        return;
    }

    // Create new node
    Node* newNode = new Node(val);

    // If index is 0, add to the front of the list
    if (index == 0) {

        newNode->next = head;   // Set new Node's next pointer to the head
        head = newNode;         // Set the head to the new node
        length++;               // Increment the length
        return;
    }

    // Create a temporary pointer to the head
    Node* current = head;

    // Traverese the list to the specified index
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Insert the new node at the index
    newNode->next = current->next;
    current->next = newNode;
    
    // Increment the length
    length++;
}


// Remove the node with the value 'val'
void LinkedList::remove(int val) {

    // If the list is empty, return
    if (head == nullptr) {
        return;
    }

    // If the head contains 'val', remove the head
    if (head->data == val) {
        Node* current = head;   // Create pointer to the head
        head = head->next;      // Set the head point to the next node
        delete current;         // Delete the old head
        length--;               // Decrement the length
        return;
    }

    // Create a temporary pointer to the head
    Node* current = head;

    // Iterate through the list
    while (current->next != nullptr) {
        // If the value is found, delete that node
        if (current->next->data == val) {
            Node* temp = current->next; 

            current->next = current->next->next;

            delete temp;
            length--;       // Decrement the length
            return;
        }

        // Continue iterating if the value is not found
        current = current->next;

    }

}

// Display the list
void LinkedList::display() const {

    // Create a pointer to the head
    Node* current = head;

    // Iterate through the list
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }

    std::cout << "nullptr\n";
}

// Return the size of the list
int LinkedList::size() const{
    return length;
}