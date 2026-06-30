#include "LinkedList.h"
#include <iostream>
#include <string>


int main() {

    // Initalize a new list
    LinkedList myList; 

    // Add elements the list
    myList.add(10);
    myList.add(30);
    myList.add(1, 20);

    // Print the list
    myList.display();

    // Remove and element
    myList.remove(30);

    // Print the list
    myList.display();

    // Get the size of the list
    std::cout << "size: " << myList.size() << "\n";

    return 0;
}


