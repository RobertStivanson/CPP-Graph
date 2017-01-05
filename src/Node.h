#ifndef NODE_H
#define NODE_H

#include <vector> // For the vector class to store Edges
#include "Edge.h" // For the Edge class

typedef std::vector<Edge> EdgeList;

// Node
// This is a class that represents a node in a graph. It houses a list for
// its edges.
class Node {
	private:
		// instance variables
		NodeID id;
		EdgeList edges;
		
		// Default constructor
		Node();
		
		// GetEdgeIndex
		// params:
		//	node: This is the node we are looking for
		// Returns the index for an edge if this node contains it
		int GetEdgeIndex(NodeID node) const;
		
	public:
		// Parameterized constructor
		// params:
		//	id: This is the id associated with the node
		Node(NodeID id);
		
		// GetID
		// Returns the ID for this node
		NodeID GetID() const;
		
		// GetEdges
		// Returns the edges for this node
		EdgeList GetEdges() const;
		
		// AddEdge
		// params:
		//	endID: This is the id associated with end of the link
		//	weight: This is the weight associated with this link
		// Adds the edge to the list of edges for this node
		bool AddEdge(NodeID endID, float weight);
		
		// RemoveEdge
		// params:
		//	endID: This is the id of the link we wish to terminate
		// Removes the associated edge from this node
		bool RemoveEdge(NodeID endID);
		
		// UpdateEdge
		// params:
		//	endID: This is the end ID of the edge we want to update
		//	newEndID: This is the new ID to be associated with this link
		//	keepWeight: Is a flag to tell if a new weight should be assigned
		//	newWeight: This is the new weight to be associated with the link, defaulted to 0
		// This function updates an edges values
		bool UpdateEdge(NodeID endID, float newEndID, bool keepWeight, float newWeight = 0);
		
		// ContainsEdge
		// params:
		//	node: This is the node we are looking for
		// Returns true if we contain this edge, false otherwise
		bool ContainsEdge(NodeID node) const;
		
		// Print
		// Prints the contents of the node
		void Print() const;
}; // End Node Class

#endif