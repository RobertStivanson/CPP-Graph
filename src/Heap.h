#ifndef HEAP_H
#define HEAP_H

#include <iostream> // For cout
#include <vector> // For the vector class

// Heap
// This is an implementation of a minimum heap. All inserted values are
// rearranged to follow heap rules. Good to use as a Priority Queue.
template <class T>
class Heap {
	private:
		std::vector<T> heap;
		
		// GetLeftChild
		// params:
		//	parent: This is the parent node we are examining
		// Returns an index to the left child, -1 if it does not exist.
		int GetLeftChild(int parent) const {
			// Calculate the left child for the parent node
			int left = (2 * parent) + 1;
			
			// If the left child is outside of the heap contents
			if (left >= heap.size()) {
				// Make the left child index invalid
				left = -1;
			}
			
			return left;
		}
		
		// GetRightChild
		// params:
		//	parent: This is the parent node we are examining
		// Returns an index to the right child, -1 if it does not exist.
		int GetRightChild(int parent) const {
			// Calculate the left child for the parent node
			int right = (2 * parent) + 2;
			
			// If the left child is outside of the heap contents
			if (right >= heap.size()) {
				// Make the left child index invalid
				right = -1;
			}
			
			return right;
		}
		
		// GetParent
		// parmas:
		//	child: This is the child whose parent we want
		// Returns the index to a childs parent, -1 if the child is the root
		int GetParent(int child) const {
			// Calculat the parent node for the child
			int parent = (child - 1) / 2;
			
			// If the child is the root node
			if (child == 0) {
				// Set the parent index to invalid
				parent = -1;
			}
			
			return parent;
		}
		
		// HeapifyUp
		// params:
		//	in: This is the node we are heapifying up from
		// Determines if this node needs to be moved up in the heap or not
		void HeapifyUp(int in) {
			int parent = GetParent(in);
			
			// If in is in range and it has a parent
			if (in >= 0 && parent >= 0) {
				// If in's parent is bigger than it 
				if (heap[parent] > heap[in]) {
					// Swap the values
					T temp = heap[in];
					heap[in] = heap[parent];
					heap[parent] = temp;
					
					// Try to heapify up again from the parent
					HeapifyUp(parent);
				}
			}
			
			return;
		}
		
		// HeapifyDown
		// params:
		//	in: This is the node we are heapifying down from
		// Determines if this node needs to be moved down in the heap or not
		void HeapifyDown(int in) {
			// Get the children for this index
			int childOne = GetLeftChild(in),
				childTwo = GetRightChild(in);
			
			// If the children exist
			if (childOne >= 0 && childTwo >= 0) {
				// If the left child is greater than the right child
				if (heap[childOne] > heap[childTwo]) {
					// Then we will move the right child up
					childOne = childTwo;
				}
			}
			
			// If we have a child to move
			if (childOne > 0) {
				// Swap the values
				T temp = heap[in];
				heap[in] = heap[childOne];
				heap[childOne] = temp;
				
				// Try to heapify down again from the child
				HeapifyDown(childOne);
			}
			
			return;
		}
		
	public:
		// Default Constructor
		// Initializes all values to default
		Heap() {
			heap.clear();
			return;
		}
		
		// Push
		// params:
		//	value: This is the value to be pushed onto the heap
		// Push the value to the end of the heap and update 
		// the heap structure
		void Push(T value) {
			// Push the new value to the heap
			heap.push_back(value);
			
			// Restructure the heap so it is correct
			HeapifyUp(heap.size() - 1);
			
			return;
		}
		
		// Pop
		// Removes the front element from the heap
		T Pop() {
			T root;
			
			// If there is something in the heap
			if (heap.size() != 0) {
				// Get the element at the root of the tree
				root = heap.front();
				
				// Bring the last element to act as the root
				heap[0] = heap.at(heap.size() - 1);
				heap.pop_back();
			
				// Restructure the heap so it is correct
				HeapifyDown(0);
			}
			
			return root;
		}
		
		// Front
		// Returns the front value of the heap
		T Front() const {
			T front;
			
			// If there is something in the heap
			if (heap.size() != 0) {
				// Get the value of the root
				front = heap[0];
			}
			
			return front;
		}
		
		// Size
		// Returns the amount of elements in the heap
		int Size() const {
			return heap.size();
		}
		
		// Empty
		// Returns true if the heap is empty, false otherwise
		bool Empty() const {
			return (heap.size() == 0);
		}
		
		// Clear
		// Removes all entries from the heap
		void Clear() {
			heap.clear();
			return;
		}
		
		// Print
		// Prints the heap in a linear fashion
		void Print() const {
			// For every element in the heap
			for (int i = 0; i < heap.size(); i++) {
				// Print the element
				std::cout << heap[i];
				
				// If this is not the last element
				if (i < heap.size() - 1) {
					// Print a seperator
					std::cout << " - ";
				}
			}
			
			std::cout << std::endl;
			
			return;
		}
};

#endif