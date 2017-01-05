#include "UnionFind.h"

// Default Constructor
// params:
//	size: This is the total size of elements that will be watched
// Creates a UnionFind data structure for (size) elements
UnionFind::UnionFind(const int & size) {
	// Allocate memory for the sets
	parents = new int[size];
	treeSize = new int[size];
	
	// For every element we are tracking
	for (int i = 0; i < size; i++) {
		// Set their parent to themselves
		// and their set size to one
		parents[i] = i;
		treeSize[i] = 1;
	}
	
	return;
}

// Destructor
// Ensures the freeing of all allocated memory
UnionFind::~UnionFind() {
	delete [] parents;
	delete [] treeSize;
	
	return;
}

// Union
// params:
//	one: This is an element in the first set to merge
//	two: This is an element in the second set to merge
// Merge two sets togethers
bool UnionFind::Union(int one, int two) {
	bool unioned = false;
	
	// Find the roots of the elements
	one = Find(one);
	two = Find(two);
	
	// If the elements are in different sets
	if (one != two) {
		// If the first set is smaller than the second
		if (treeSize[one] < treeSize[two]) {
			// Append the first set to the second
			parents[one] = two;
			treeSize[two] += treeSize[one];
			
		// If the second set is smaller than the first
		} else {
			// Append the second set to the first
			parents[two] = one;
			treeSize[one] += treeSize[two];
		}
		
		unioned = true;
	}
	
	return unioned;
}

// Find
// params:
//	one: This is the element we are looking to find
//	Returns the root of the set that this element is in
int UnionFind::Find(int one) {
	int root = one;
	
	// While the elements parent is not itself
	while (root != parents[root]) {
		// Set the new root to the elements parent
		root = parents[root];
	}
	
	return root;
}