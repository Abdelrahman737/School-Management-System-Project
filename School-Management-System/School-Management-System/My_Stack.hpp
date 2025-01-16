#include <iostream>
#include "List.hpp" // Assuming this defines LinkedList
using namespace std;

// Template class for Stack
template <typename T>
class Stack {
private:
    LinkedList<T>* list; // Pointer to a LinkedList managing the stack items

public:
    Stack() 
    {
        list = new LinkedList<T>(); // Initialize the LinkedList
    }

    ~Stack() 
    {
        delete list; // Clean up the LinkedList
    }

    // Check if the stack is empty
    bool isEmpty() const 
    {
        return list->isEmpty(); // Delegate to LinkedList's isEmpty method
    }

    // Push an item onto the stack
    bool push(const T& newItem) 
    {
        return list->add(newItem); // Assume addFront adds to the front of the list
    }

    // Pop the top item from the stack
    bool pop() 
    {
        if (isEmpty()) 
        {
            return false;
        }

        return list->removeBack(); // Assume removeFront removes the front item
    }

    // Pop the top item and retrieve it
    bool pop(T& stackTop) 
    {
        if (isEmpty()) 
        {
            return false;
        }

        stackTop = list->getBack(); // Assume getFront retrieves the front item without removing it
        
		list->removeBack(); // Remove the top item

        return true;
    }

    // Retrieve the top item without removing it
    bool getTop(T& stackTop) const {
        if (isEmpty()) {
            return false;
        }
        stackTop = list->getBack();

        return true;
    }

    // Get the current size of the stack
    int size() const 
    {
        return list->getCurrentSize(); // Delegate to LinkedList's size method
    }

    // Display the stack contents
    void display() const 
    {
        list->display(); // Assume display prints all items in the list
    }
};
