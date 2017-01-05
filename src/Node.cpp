#include <iostream>
#include "Node.h"

// Default Constructor
// Initializes the node to default values
Node::Node() : id(0) {
	edges.clear();
	return;
}

// Parameterized constructor
// params:
//	id: This is the id associated with the node
Node::Node(NodeID id) : id(id) {
	edges.clear();
	return;
}

// GetID
// Returns the ID for this node
NodeID Node::GetID() const {
	return id;
}

// GetEdges
// Returns the edges for this node
EdgeList Node::GetEdges() const {
	return edges;
}

// AddEdge
// params:
//	endID: This is the id associated with end of the link
//	weight: This is the weight associated with this link
// Adds the edge to the list of edges for this node
bool Node::AddEdge(NodeID endID, float weight) {
	bool added = false;
	
	// If we don't already contain this edge
	// and the end node isn't this node
	if (!ContainsEdge(endID) && (endID != id)) {
		// Add the edge to our list of edges
		edges.push_back(Edge(id, endID, weight));
		
		// We added the edge
		added = true;
	}
	
	return added;
}

// RemoveEdge
// params:
//	endID: This is the id of the link we wish to terminate
// Removes the associated edge from this node
bool Node::RemoveEdge(NodeID endID) {
	bool removed = false;
	
	// If this edge exists
	// and the end node isn't this node
	if (ContainsEdge(endID) && (endID != id)) {
		// Remove this edge from our list of edges
		edges.erase(edges.begin() + GetEdgeIndex(endID));
		
		// We removed the edge
		removed = true;
	}
	
	return removed;
}

// UpdateEdge
// params:
//	endID: This is the end ID of the edge we want to update
//	newEndID: This is the new ID to be associated with this link
//	keepWeight: Is a flag to tell if a new weight should be assigned
//	newWeight: This is the new weight to be associated with the link, defaulted to 0
// This function updates an edges values
bool Node::UpdateEdge(NodeID endID, float newEndID, bool keepWeight, float newWeight) {
	bool updated = false;
	
	// If this edge exists
	// and the end node isn't this node
	if (ContainsEdge(endID) && (newEndID != id)) {
		int endIndex = GetEdgeIndex(endID);
		
		// Add the edge to the list with the new information
		AddEdge(newEndID, (keepWeight ? edges[endIndex].GetWeight() : newWeight));
		
		// Remove this edge from our list of edges
		edges.erase(edges.begin() + endIndex);
		
		// We removed the edge
		updated = true;
	}
	
	return updated;
}

// ContainsEdge
// params:
//	node: This is the node we are looking for
// Returns true if we contain this edge, false otherwise
bool Node::ContainsEdge(NodeID node) const {
	return (GetEdgeIndex(node) != -1);
}

// GetEdgeIndex
// params:
//	node: This is the node we are looking for
// Returns the index for an edge if this node contains it
int Node::GetEdgeIndex(NodeID node) const {
	int index = -1;
	
	// If the node we are looking for is not this node
	if (node != id) {
		// For every edge while we havent found the edge
		for (int i = 0; (i < edges.size()) && (index == -1); i++) {
			// If this is the edge we are looking for
			if (edges[i].GetID() == node) {
				// Get the index
				index = i;
			}
		}
	}
	
	return index;
}

// Print
// Prints the contents of the node
void Node::Print() const {
	// Print the nodes ID
	std::cout << id;
	
	// For every edge
	for (int i = 0; i < edges.size(); i++) {
		// Print the edges information
		std::cout << " - ";
		edges[i].Print();
	}
	
	return;
}