#ifndef UNION_FIND_H
#define UNION_FIND_H

// UnionFind
// The UnionFind data structure acts a set management utility
// where you can detect the sets of a given value and merge sets.
// This is used for Kruskal's Algorithm

class UnionFind {
	private:
		int * parents,  // Used to create a parent array for all elements 
			* treeSize; // Tracks the size of the sets element is in
		
	public:
		// Default Constructor
		// params:
		//	size: This is the total size of elements that will be watched
		// Creates a UnionFind data structure for (size) elements
		UnionFind(const int & size);
		
		// Destructor
		// Ensures the freeing of all allocated memory
		~UnionFind();
		
		// Union
		// params:
		//	one: This is an element in the first set to merge
		//	two: This is an element in the second set to merge
		// Merge two sets togethers
		bool Union(int one, int two);
		
		// Find
		// params:
		//	one: This is the element we are looking to find
		//	Returns the root of the set that this element is in
		int Find(int one);
};

#endif