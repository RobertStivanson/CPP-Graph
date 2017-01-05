#ifndef EDGE_H
#define EDGE_H

typedef int NodeID;

// Edge
// This class represents a weight link between two nodes
class Edge {
	private:
		// instance variables
		NodeID startID, endID;
		float weight;
		
		// Default constructor
		Edge();
	
	public:
		// Parameterized Constructor
		// params:
		//	endID: This is the id associated with the node at the end of the LinkedList
		//	weight: This is the weight for the given link
		Edge(NodeID startID, NodeID endID, float weight = 0);
		
		// GetStartID
		// Returns the start node ID of this edge
		NodeID GetStartID() const;
		
		// GetID
		// Returns the end node ID of this edge
		NodeID GetID() const;
		
		// GetWeight
		// Returns the weight associated with this edge
		float GetWeight() const;
		
		// Print
		// Prints the edges data in the format:
		// endID(weight)
		void Print() const;
		
		// Operator < Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a less than check between this and the passed edge
		bool operator < (const Edge & edge) const;
		
		// Operator <= Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a less than or equal to check between this and the passed edge
		bool operator <= (const Edge & edge) const;
		
		// Operator > Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a greater than check between this and the passed edge
		bool operator > (const Edge & edge) const;
		
		// Operator >= Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a greater than or equal to check between this and the passed edge
		bool operator >= (const Edge & edge) const;
		
		// Operator == Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a equal to check between this and the passed edge
		bool operator == (const Edge & edge) const;
		
		// Operator != Overload
		// params:
		//	edge: This is the edge we are comapring against
		// Performs a not equal to check between this and the passed edge
		bool operator != (const Edge & edge) const;
}; // End Edge Class

#endif