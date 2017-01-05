#include <iostream>
#include "Edge.h"

// Default constructor
Edge::Edge() {
	return;
}
// Parameterized Constructor
// params:
//	endID: This is the id associated with the node at the end of the LinkedList
//	weight: This is the weight for the given link
Edge::Edge(NodeID startID, NodeID endID, float weight) : startID(startID), endID(endID), weight(weight) {
	return;
}

// GetStartID
// Returns the start node ID of this edge
NodeID Edge::GetStartID() const {
	return startID;
}

// GetID
// Returns the end ndoe ID of this edge
NodeID Edge::GetID() const {
	return endID;
}

// GetWeight
// Returns the weight associated with this edge
float Edge::GetWeight() const {
	return weight;
}

// Print
// Prints the edges data in the format:
// endID(weight)
void Edge::Print() const {
	std::cout << "(" << startID << ", " << endID << " (wght: " << weight << "))";
	return;
}

// Operator < Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a less than check between this and the passed edge
bool Edge::operator < (const Edge & edge) const {
	return (weight < edge.weight);
}

// Operator <= Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a less than or equal to check between this and the passed edge
bool Edge::operator <= (const Edge & edge) const {
	return (weight <= edge.weight);
}

// Operator > Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a greater than check between this and the passed edge
bool Edge::operator > (const Edge & edge) const {
	return (weight > edge.weight);
}

// Operator >= Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a greater than or equal to check between this and the passed edge
bool Edge::operator >= (const Edge & edge) const {
	return (weight >= edge.weight);
}

// Operator == Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a equal to check between this and the passed edge
bool Edge::operator == (const Edge & edge) const {
	return (startID == edge.startID && 
			endID == edge.endID && 
			weight == edge.weight);
}

// Operator != Overload
// params:
//	edge: This is the edge we are comapring against
// Performs a not equal to check between this and the passed edge
bool Edge::operator != (const Edge & edge) const {
	return (startID != edge.startID || 
			endID != edge.endID || 
			weight != edge.weight);
}