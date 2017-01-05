#include <iostream>
#include <cmath>
#include "UnionFind.h"
#include "Heap.h"
#include "Graph.h"

//Default constructor
Graph::Graph() {
	Clear();
	return;
}

// GetNumVertices
// Returns the number of vertices in the graph
int Graph::GetNumVertices() const {
	return vertices;
}

// GetNumEdges
// Returns the number of edges in the graph
int Graph::GetNumEdges() const {
	return edges;
}

// AddNode
// Add the node to the adjacency list, returns the new nodes ID
int Graph::AddNode() {
	// Add the entry to the adjacency list
	// and increment the number of vertices
	adjList.push_back(Node(vertices++));
	
	return (vertices - 1);
}

/*// RemoveNode
// params:
//	node: This is the node we wish to remove from the graph
// Removes the node from the adjancy list, if it exists
bool Graph::RemoveNode(NodeID node) {
	bool removed = false;
	
	// If the graph contains the node
	if (Contains(node)) {
		// Erase this node from the adjacency list
		adjList.erase(adjList.begin() + GetIndex(node));
		
		// For every node in our adjacency list
		for (int i = 0; i < adjList.size(); i++) {
			// Remove any edge to the node we are removing
			adjList[i].RemoveEdge(node);
		}
		
		// Decrement the number of vertices
		vertices--;
		
		// We removed the node
		removed = true;
	}
	
	return removed;
}*/

// AddEdge
// params:
//	startID: This is the node id of the starting node
//	endID: This is the node id of the ending node
//	weight: This is the weight associated with this link
//	directed: This is a flag if the link is bidirectional or not
// Adds the edge between the start and end node, if directional is false
// then an edge will be added between end and start as well.
bool Graph::AddEdge(NodeID startID, NodeID endID, float weight, bool directed) {
	bool added = false;
	
	// If the graph contains the starting and ending node
	if (ContainsPair(startID, endID)) {
		// Add the edge from the starting node to the ending node
		adjList[GetIndex(startID)].AddEdge(endID, weight);
		
		// Increment the number of edges
		edges++;
		
		// If this link is not directed
		if (!directed) {
			// Add the edge from the ending node to the starting node
			adjList[GetIndex(endID)].AddEdge(startID, weight);
			
			// Increment the number of edges
			edges++;	
		}
		
		// We added the edge
		added = true;
	}
	
	return added;
}

// RemoveEdge
// params:
//	startID: This is the node id of the starting node
//	endID: This is the node id of the ending node
// This removes all edges between these two node, the removal is
// not directional
bool Graph::RemoveEdge(NodeID startID, NodeID endID) {
	bool removed = false;
	
	// If the graph contains both the starting and ending node
	if (ContainsPair(startID, endID)) {
		// Remove the edge between the starting and ending node
		if (adjList[GetIndex(startID)].RemoveEdge(endID))
			// Decrement the number of edges
			edges--;
		
		// Remove the edge between the ending and starting node
		if (adjList[GetIndex(endID)].RemoveEdge(startID))
			// Decrement the number of edges
			edges--;
		
		// We removed the edges
		removed = true;
	}
	
	return removed;
}

// GetEdges
// params:
//	node: This is the node for whose neighbors we want
// Returns an EdgeList with all neighbors for that node
EdgeList Graph::GetNodeEdges(NodeID node) const {
	if (node >= 0 && node < adjList.size())
		return adjList[node].GetEdges();
	return EdgeList();
}

// Contains
// params:
//	node: This is the node we are looking for
// Returns true if the graph contains the node, false otherwise
bool Graph::Contains(NodeID node) const {
	return (GetIndex(node) != -1);
}

// ContainsPair
// params:
//	nodeOne: This is the first node we are looking for
//	nodeTwo: This is the second node we are looking for
// Returns true if the graph contains both nodes, false otherwise
bool Graph::ContainsPair(NodeID nodeOne, NodeID nodeTwo) const {
	bool containsFirst = false, containsSecond = false;
	
	// For every node while we haven't found both nodes
	for (int i = 0; (i < adjList.size()) && (!containsFirst || !containsSecond); i++) {
		// If this is a node we are looking for
		if (adjList[i].GetID() == nodeOne) {
			containsFirst = true;
		}
		
		// If this is a node we are looking for
		if (adjList[i].GetID() == nodeTwo) {
			containsSecond = true;
		}
	}
	
	return (containsFirst && containsSecond);
}

// GetIndex
// params:
//	node: This is the node we wish to find
// Finds the given node and returns its index
int Graph::GetIndex(NodeID node) const {
	int index = -1;
	
	// For every node while we haven't found the node
	for (int i = 0; (i < adjList.size()) && (index == -1); i++) {
		// If this is the node we are looking for
		if (adjList[i].GetID() == node) {
			// Get its index
			index = i;
		}
	}
	
	return index;
}


// Quicksort
// params:
//	edges: This is the list of edges to sort
//	size: This is the size of the array in which is being sorted
// Performs the Quicksort algorithm on the list of edges
void Graph::QuickSort(EdgeList & edges, const int & low, const int & high) const {
	// If the gap is greater than one
	if (low < high) {
		// Create a partition point
		int partition = Partition(edges, low, high);
		
		// Sort the sub arrays
		QuickSort(edges, low, (partition - 1));
		QuickSort(edges, (partition + 1), high);
	}
	
	return;
}

// Clear
// Resets all values used to by the graph to a default value
void Graph::Clear() {
	adjList.clear();
	vertices = 0;
	edges = 0;
	
	return;
}

// Partition
// params:
//	edges: This is the list of edges to sort
//	low: This is the lower bound index in the array to partition
//	high: This is the higher bound index in the array to partition
// Takes the edges and returns a partition point used in the Quick sort algorithm
int Graph::Partition(EdgeList & edges, const int & low, const int & high) const {
	Edge temp(0, 0), pivot(edges[high]);
	int i = low;
	
	// For every element in the sub array
	for (int j = low; j < high; ++j) {
		// If this element is less than our pivot
		if (edges[j] < pivot) {
			// Swap the elements
			temp = edges[i];
			edges[i] = edges[j];
			edges[j] = temp;
			
			++i;
		}
	}
	
	// Swap the lowest elements and the last element
	temp = edges[i];
	edges[i] = edges[high];
	edges[high] = temp;
	
	return i;
}

// GetSortedEdges
// Gathers and sorts a list of all edges
EdgeList Graph::GetSortedEdges() const {
	EdgeList e;
	
	// For every node in the adjacency list
	for (int i = 0; i < adjList.size(); i++) {
		// Get the nodes edges
		EdgeList tmp = adjList[i].GetEdges();
		
		// Compile them with the other edges
		e.insert(e.begin(), tmp.begin(), tmp.end());
	}
	
	// Sort the edges
	QuickSort(e, 0, e.size() - 1);
	
	return e;
}

// PrimsAlgorithm
// params:
//	start: This is the starting node for the produced MSF
// Runs Prim's Algorithm on the graph and returns the produced MSF
AdjList Graph::PrimsAlgorithm(NodeID start) const {
	AdjList mst;
	EdgeList n;
	Heap <PrimsNode> nodes;
	PrimsNode temp, min, updated;
	float costs[adjList.size()];
	bool visited[adjList.size()];
	int edgeCounter = 0;
	
	// Clamp start inside the bounds of the graphs
	if (start < 0 || start >= adjList.size())
		start = 0;
	
	// For every vertice
	for (int i = 0; i < adjList.size(); i++) {
		// Push back every node
		mst.push_back(Node(i));
		
		// Prepare them for prims algorithm
		temp.node = adjList[i].GetID();
		
		// If this is the starting node
		if (i == start) {
			// Set this node to root values
			temp.cost = 0;
			costs[i] = 0;
		} else {
			// Set the costs to infinity
			temp.cost = INFINITY;
			costs[i] = INFINITY;
		}
		
		// Set the nodes to not being visited
		visited[i] = false;
		// And the parents to themselves
		temp.parent = i;
		
		nodes.Push(temp);
	}
	
	// While we don't have V-1 edges in our MST
	while (edgeCounter < adjList.size() - 1) {
		// Get the node with the minimum cost and its neighbors
		min = nodes.Pop();
		n = adjList[min.node].GetEdges();
		
		// If this node has not already been visited
		if (!visited[min.node]) {
			visited[min.node] = true;
			
			// If this node is not the root node
			if (min.node != start) {
				// Add a bidirectional connection between the two points
				mst[min.parent].AddEdge(min.node, min.cost);
				mst[min.node].AddEdge(min.parent, min.cost);
				
				// Increment the edge counter
				edgeCounter++;
			}
			
			// For every neighbor to this node
			for (int i = 0; i < n.size(); i++) {
				// If this node has not been visited already and if
				// the cost of the current weight plus the edge is better
				if (!visited[n[i].GetID()] && (min.cost + n[i].GetWeight()) < costs[n[i].GetID()]) {
					// Create a new node with the updated values
					updated.node = n[i].GetID();
					updated.parent = min.node;
					updated.cost = min.cost + n[i].GetWeight();
					
					// Update the cost values
					costs[n[i].GetID()] = min.cost + n[i].GetWeight();
					
					// Push the new node to the heap
					nodes.Push(updated);
				}
			}
		}
	}
	
	return mst;
}

// KruskalsAlgorithm
// Performs Kruskals Algorithm on the current state of the
// graph and returns an EdgeList that makes a MSF
AdjList Graph::KruskalsAlgorithm() const {
	AdjList mst;
	EdgeList e = GetSortedEdges();
	
	// Initialize an adjancy list for the MST
	for (int i = 0; i < adjList.size(); i++) {
		// Push back every node
		mst.push_back(Node(i));
	}
	
	// Create a UnionFind DS with the size of the amount of nodes
	UnionFind ufn(adjList.size());
	
	// For every edge in the sorted edges list
	for (int i = 0; i < e.size(); i++) {
		// Find the set that each point belongs to
		NodeID x = ufn.Find(e[i].GetStartID()),
			   y = ufn.Find(e[i].GetID());
		
		// If the points are not in the same set
		if (x != y) {
			// Merge the sets
			ufn.Union(x, y);
			
			// Add a bidirectional connection between the two points
			mst[e[i].GetStartID()].AddEdge(e[i].GetID(), e[i].GetWeight());
			mst[e[i].GetID()].AddEdge(e[i].GetStartID(), e[i].GetWeight());
		}
	}
	
	return mst;
}

// Print
// Prints the adjacency list of this graph
void Graph::Print() const {
	// For every node in the adjacency list
	for (int i = 0; i < adjList.size(); i++) {
		// Print the node
		adjList[i].Print();

		// Move to the next line
		std::cout << std::endl;
	}
	
	return;
}