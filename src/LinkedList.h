#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string> // Used for the string data type

// LinkedList
// This class is a list container where each element is connected by pointers. It is
// dynamic so that is can grow indefinitely;
template <class T>
class LinkedList {
	private:
		// ListNode
		// This is the node struct that the LinkedList class uses for each
		// element in the list
		struct ListNode {
			ListNode * next;
			T data;
		};
		
		// Pointers to the beginning and end of the list
		ListNode * head, * tail;
		// This is the amount of elements in the list
		int size;
		
	public:
		// Default Constructor
		// Initializes the list to nothing
		LinkedList() : head(NULL), tail(NULL), size(0) {
			return;
		}
		
		// Parameterized Constructor
		// params:
		//	list: This it the list we wish to copy
		// Initializes the list to be the same as the passed list
		LinkedList(const LinkedList<T> & list) {
			ListNode * curNode = list.head, * prevNode = NULL, * newHead = NULL, * newTail = NULL;
			int newSize = 0;
			
			// While there are nodes to copy
			while (curNode != NULL) {
				// Create a new node
				ListNode * newNode = new ListNode;
				newNode->next = NULL;
				newNode->data = curNode->data;
				
				// If there is no head node
				if (newHead == NULL) {
					// Make this node the head node
					newHead = newNode;
					newTail = newNode;
				} else {
					// Add this node to the tail
					newTail->next = newNode;
					newTail = newNode;
				}
				
				// Increment the size
				newSize++;
				
				// Move to the next node
				prevNode = curNode;
				curNode = curNode->next;
			}
			
			// Assign the new list
			head = newHead;
			tail = newTail;
			size = newSize;
			
			return;
		}
		
		// Destructor
		// Makes sure all node are safely removed from memory
		~LinkedList() {
			Clear();
			return;
		}
		
		// Push
		// params:
		//	data: the data to be held in a node
		// Adds a new node to the end of the list with the given data
		void Push(T data) {
			// Create a new node
			ListNode * newNode = new ListNode;
			newNode->next = NULL;
			
			// Add the data to the node
			newNode->data = data;
			
			// If there is no head node
			if (head == NULL) {
				// Make this node the head
				head = newNode;
				tail = newNode;
			} else {
				// Add this node to the tail
				tail->next = newNode;
				tail = newNode;
			}
			
			// Increment the size
			size++;
			
			return;
		}
		
		// Remove
		// params:
		//	data: the data to be held in a node
		// Removes the given data from the list
		bool Remove(T data) {
			bool removed = false;
			
			// If the list is not empty
			if (!Empty()) {
				ListNode * previous = NULL;
				
				// For every node
				for (ListNode * node = head; node != NULL && !removed; node = node->next) {
					// If this is the node we are looking for
					if (node->data == data) {
						// If this is the head node
						if (node == head) {
							// Set the head to the next node
							head = node->next;
							
						// If this is not the head node
						} else {
							// Set the previous node's next to the next node
							previous->next = node->next;
						}
						
						// Free the allocated memory
						delete node;
						
						// Decrement the size
						size--;
						
						// We removed the item
						removed = true;
						
					// If this is not what we are looking for
					} else {
						// Set this to be the previous node
						previous = node;
					}
				}
			}
			
			return removed;
		}
		
		// Front
		// Returns the data at the front of the list
		T Front() {
			if (Empty()) {
				return T();
			}
			
			return head->data;
		}
		
		// End
		// Returns the data at the back of the list
		T End() {
			if (Empty()) {
				return T();
			}
			
			return tail->data;
		}
		
		// Pop
		// Removes the node at the front of the list and returns its data
		T PopFront() {
			// If there is nothing in the front of the list
			if (Empty()) {
				return T();
			}
			
			// Take the first node out and move the head to the next node
			ListNode * poppedNode = head;
			head = head->next;
			
			// Get the data from the node
			T poppedData = poppedNode->data;
			
			// Delete the node so it is no longer in memory
			delete poppedNode;
			size--;
			
			return poppedData;
		}
		
		// Clear
		// Deletes every node in the list from memory
		void Clear() {
			ListNode * current = head, * next;
			
			// While there is still a node to remove
			while (current != NULL) {
				// Get the next node
				next = current->next;
				
				// Remove the current node from memory and the list
				delete current;
				
				// Go to the next node
				current = next;
			}
			
			// Remove any dangling pointers
			head = NULL;
			
			return;
		}
		
		// Size
		// Returns the count of elements in the list
		int Size() const {
			return size;
		}
		
		// Empty
		// Returns true if the list has no nodes in it
		bool Empty() const {
			return (head == NULL);
		}
		
		// Print
		// Prints the data for every node in the list. format: Item #i\t: {data}
		void Print(bool list = true) const {
			// If the list is not empty
			if (!Empty()) {
				int id = 0;
				
				// For every node
				for (ListNode * node = head; node != NULL; node = node->next) {
					// Print its information in list form
					if (list) {
						std::cout << "Item #" << id << "\t: " << node->data << std::endl;
						++id;
						
					// Print its information inline
					} else {
						std::cout << node->data;
						
						// if this is not the last element
						if (node->next != NULL) {
							std::cout << " - ";
						}
					}
				}
			} else { // If the list is empty
				std::cout << "The list is empty, there is nothing to print!" << std::endl;
			}
			
			std::cout << std::endl;
			
			return;
		}
		
		// operator= Overload
		// params:
		//	list: This it the list we wish to copy
		// Deletes the current list and sets this equal to a copy of the given list
		LinkedList<T> & operator=(const LinkedList<T> & list) {
			if (this == &list) {
				return *this;
			}
			
			ListNode * curNode = list.head, * prevNode = NULL, * newHead = NULL, * newTail = NULL;
			int newSize = 0;
			
			// Clear the list of any current contents
			Clear();
			
			// While there are nodes to copy
			while (curNode != NULL) {
				// Create a new node and copy its data
				ListNode * newNode = new ListNode;
				newNode->next = NULL;
				newNode->data = curNode->data;
				
				// If we dont have a head node
				if (newHead == NULL) {
					// Make this node the head
					newHead = newNode;
					newTail = newNode;
				} else {
					// Add this node to the tail
					newTail->next = newNode;
					newTail = newNode;
				}
				
				// Increment the size
				newSize++;
				
				// Move to the next node
				prevNode = curNode;
				curNode = curNode->next;
			}
			
			// Assign the new list to this list
			head = newHead;
			tail = newTail;
			size = newSize;
			
			return *this;
		}
		
		// operator[] Overload
		// params:
		//	index: this is the index we are indexing into
		// Iterates through the list and returns the value at the index
		T & operator[](std::size_t index) {
			ListNode * n = head;
			
			if (index >= 0 && index < size) {
				for (int i = 0; i < index; i++) {
					n = n->next;
				}
			}
			
			return n->data;
		}
};

#endif