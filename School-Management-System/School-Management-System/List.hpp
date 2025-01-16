#include <iostream>
using namespace std;

// Template class for Node
template <typename T>
class Node {
public:
    T item;         // Data of any type
    Node* next;     // Pointer to the next node

	// Constructor
    Node(const T& data) : item(data), next(nullptr) {}
};

// Template class for LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* headPtr; // Pointer to the first node in the list
    int itemCount;    // Current count of items

public:

    LinkedList() : headPtr(nullptr), itemCount(0) 
    {

    }

    ~LinkedList() 
    {
        clear();
    }

	// Add an item to the linked list
    bool add(const T& newItem)
    {
        Node<T>* newNodePtr = new Node<T>(newItem);
        if (isEmpty())
        {
            headPtr = newNodePtr;
        }
        else
        {
            Node<T>* current = headPtr;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNodePtr;
        }
        itemCount++;
        return true;
    }

	// Remove an item from the linked list
    bool remove(const T& itemToRemove) 
    {
        Node<T>* prev = nullptr;
        Node<T>* curr = headPtr;

        while (curr != nullptr) 
        {
            if (curr->item == itemToRemove) 
            {
                if (prev == nullptr) 
                {
                    headPtr = curr->next;  // Removing head
                }
                else 
                {
                    prev->next = curr->next;
                }
                delete curr;
                itemCount--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

	// Remove the last item from the linked list
    bool removeBack() 
    {
        if (isEmpty()) 
        {
            return false;
        }

		// If there is only one item in the list
        if (headPtr->next == nullptr) 
        { 
            delete headPtr;
            headPtr = nullptr;
			itemCount--;
        }
        else 
        {
            Node<T>* current = headPtr;
            while (current->next->next != nullptr) 
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
			itemCount--;
        }
        return true;
    }

	// Get the last item from the linked list
	T getBack() const
	{
		if (isEmpty())
		{
			return T();
		}
		Node<T>* current = headPtr;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->item;
	}

	// Find an item in the linked list
    bool find(const T& item) const 
    {
        Node<T>* curr = headPtr;
        while (curr != nullptr) 
        {
            if (curr->item == item) 
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Display the list
    void display() const 
    {
        Node<T>* curr = headPtr;
        while (curr != nullptr) 
        {
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Clear the linked list
    void clear() 
    {
        while (headPtr != nullptr) 
        {
            Node<T>* nodeToDelete = headPtr;
            headPtr = headPtr->next;
            delete nodeToDelete;
        }
        itemCount = 0;
    }

    // Get the current size of the linked list
    int getCurrentSize() const 
    {
        return itemCount;
    }

    // Check if the list is empty
    bool isEmpty() const 
    {
        return itemCount == 0;
    }
};