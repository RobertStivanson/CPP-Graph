#ifndef GRAPH_H
#define GRAPH_H

#include <vector> // For the vector class
#include "Node.h" // For the node class

typedef std::vector<Node> AdjList;

// Graph
// This is a class that represents a graph. Nodes can be added and directional
// and bidirectional links with weights can be added between any two nodes.
class Graph {
	private:
		AdjList adjList; // This is the adjancency list
		int vertices, edges; // These are the counts of vertices and edges
		
		// Prims node
		// This is a data structure used when Prims Algorithm is ran
		struct PrimsNode {
			NodeID node;
			NodeID parent;
			float cost;
			
			// Operator > Overload
			// params:
			//	pn: This is the PrimsNode we are comapring against
			// Performs a greater than check between this and the passed PrimsNode
			bool operator > (const PrimsNode & pn) const {
				return (cost > pn.cost);
			}
		};
		
		// ContainsPair
		// params:
		//	nodeOne: This is the first node we are looking for
		//	nodeTwo: This is the second node we are looking for
		// Returns true if the graph contains both nodes, false otherwise
		bool ContainsPair(NodeID nodeOne, NodeID nodeTwo) const;
		
		// GetIndex
		// params:
		//	node: This is the node we wish to find
		// Finds the given node and returns its index
		int GetIndex(NodeID node) const;
		
		// Quicksort
		// params:
		//	edges: This is the list of edges to sort
		//	size: This is the size of the array in which is being sorted
		// Performs the Quicksort algorithm on the list of edges
		void QuickSort(EdgeList & edges, const int & low, const int & high) const;

		// Partition
		// params:
		//	edges: This is the list of edges to sort
		//	low: This is the lower bound index in the array to partition
		//	high: This is the higher bound index in the array to partition
		// Takes the edges and returns a partition point used in the Quick sort algorithm
		int Partition(EdgeList & edges, const int & low, const int & high) const;
		
		// GetSortedEdges
		// Gathers and sorts a list of all edges
		EdgeList GetSortedEdges() const;
		
	public:
		//Default constructor
		Graph();
		
		// GetNumVertices
		// Returns the number of vertices in the graph
		int GetNumVertices() const;
		
		// GetNumEdges
		// Returns the number of edges in the graph
		int GetNumEdges() const;
		
		// AddNode
		// Add the node to the adjacency list, returns the new nodes ID
		int AddNode();
		
		// RemoveNode
		// params:
		//	node: This is the node we wish to remove from the graph
		// Removes the node from the adjancy list, if it exists
		//bool RemoveNode(NodeID node);
		
		// AddEdge
		// params:
		//	startID: This is the node id of the starting node
		//	endID: This is the node id of the ending node
		//	weight: This is the weight associated with this link
		//	directed: This is a flag if the link is bidirectional or not
		// Adds the edge between the start and end node, if directional is false
		// then an edge will be added between end and start as well.
		bool AddEdge(NodeID startID, NodeID endID, float weight = 0, bool directed = false);
		
		// RemoveEdge
		// params:
		//	startID: This is the node id of the starting node
		//	endID: This is the node id of the ending node
		// This removes all edges between these two node, the removal is
		// not directional
		bool RemoveEdge(NodeID startID, NodeID endID);
		
		// GetEdges
		// params:
		//	node: This is the node for whose neighbors we want
		// Returns an EdgeList with all neighbors for that node
		EdgeList GetNodeEdges(NodeID node) const;
		
		// Contains
		// params:
		//	node: This is the node we are looking for
		// Returns true if the graph contains the node, false otherwise
		bool Contains(NodeID node) const;
		
		// Clear
		// Resets all values used to by the graph to a default value
		void Clear();
		
		// PrimsAlgorithm
		// params:
		//	start: This is the starting node for the produced MSF
		// Runs Prim's Algorithm on the graph and returns the produced MSF
		AdjList PrimsAlgorithm(NodeID start = 0) const;
		
		// KruskalsAlgorithm
		// Performs Kruskals Algorithm on the current state of the
		// graph and returns an EdgeList that makes a MSF
		AdjList KruskalsAlgorithm() const;
		
		// Print
		// Prints the adjacency list of this graph
		void Print() const;
};

#endif