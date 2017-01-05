#include <iostream>
#include "Graph.h"
#include "UnionFind.h"
#include "Heap.h"

using namespace std;

void TestUnionFindClass();
void TestGraphClass();
void TestEdgeClass();
void TestNodeClass();
void TestHeapClass();

int main () {
	TestUnionFindClass();
	TestHeapClass();
	TestEdgeClass();
	TestNodeClass();
	TestGraphClass();
	
	return 0;
}

// TestGraphClass
// Performs tests on all public Graph class functions
void TestGraphClass() {
	
	cout << " ---------- Testing the Graph class" << endl;
	
	cout << "Creating a blank graph class" << endl;
	Graph g;
	cout << "V: " << g.GetNumVertices() << "\t\tE: " << g.GetNumEdges() << endl;
	
	cout << "Adding 6 nodes to the graph" << endl;
	for(int i = 1; i < 7; i++) {
		g.AddNode();
	}
	
	cout << "V: " << g.GetNumVertices() << "\t\tE: " << g.GetNumEdges() << endl;
	cout << "Printing the graph class" << endl;
	g.Print();
	
	cout << "Adding a bidirectional edge for pairs: ";
	cout << " (1,2) wght 5 (1,3) wght 3 (0,2) wght 6";
	cout << " (0,1) wght 19 (4, 2) wght 7 ";
	cout << " (4, 10) wght 7 (10, 4) wght 7" << endl;
	g.AddEdge(1, 2, 5);
	g.AddEdge(1, 3, 3);
	g.AddEdge(0, 2, 9);
	g.AddEdge(0, 1, 19);
	g.AddEdge(4, 2, 7);
	
	g.AddEdge(4, 10, 7);
	g.AddEdge(10, 4, 7);
	
	cout << "Adding a directional edge for pairs: ";
	cout << "(3,0) wght 12 (3,2) wght 1 (4, 3) wght 1" << endl;
	g.AddEdge(3, 0, 12, true);
	g.AddEdge(3, 2, 1, true);
	g.AddEdge(4, 3, 1, true);
	
	cout << "V: " << g.GetNumVertices() << "\t\tE: " << g.GetNumEdges() << endl;
	cout << "Printing the graph class" << endl;
	g.Print();
	
	cout << "Removing all directional links" << endl;
	g.RemoveEdge(3, 0);
	g.RemoveEdge(3, 2);
	g.RemoveEdge(4, 3);
	
	cout << "Removing the links: (1, 2) (4, 10) (10, 4)" << endl;
	g.RemoveEdge(1, 2);
	g.RemoveEdge(4, 10);
	g.RemoveEdge(10, 4);
	
	cout << "V: " << g.GetNumVertices() << "\t\tE: " << g.GetNumEdges() << endl;
	cout << "Printing the graph class" << endl;
	g.Print();
	cout << endl;
	
	cout << "Setting up a new graph for the algorithms..." << endl;
	g.Clear();
	
	for (int i = 0; i < 6; i++) {
		g.AddNode();
	}
	
	g.AddEdge(0, 1, 1);
	g.AddEdge(0, 2, 4);
	g.AddEdge(0, 3, 1);
	g.AddEdge(1, 4, 7);
	g.AddEdge(2, 3, 2);
	g.AddEdge(2, 4, 4);
	g.AddEdge(2, 5, 1);
	g.AddEdge(3, 4, 1);
	g.AddEdge(3, 5, 7);
	
	g.Print();
	cout << endl;
	cout << "         (0) " << endl;
	cout << "        / | \\ " << endl;
	cout << "       /  |  \\ " << endl;
	cout << "      /   |   \\ " << endl;
	cout << "     1    4    1 " << endl;
	cout << "    /     |     \\ " << endl;
	cout << "   /      |      \\ " << endl;
	cout << "  /       |       \\ " << endl;
	cout << "(3)--2---(2)      (1) " << endl;
	cout << " |\\     / |       / " << endl;
	cout << " | 7   1  |      / " << endl;
	cout << " |  \\ /   |     / " << endl;
	cout << " \\  (5)   |    / " << endl;
	cout << "  1       4   7 " << endl;
	cout << "   \\_____ | _/ " << endl;
	cout << "         (4) " << endl;
	cout << endl;
	cout << "Running Kruskals Algorithm" << endl;
	AdjList el =  g.KruskalsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl << "Running Prims Algorithm" << endl;
	el =  g.PrimsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl;
	cout << "Setting up a new graph for the algorithms in a different order..." << endl;
	g.Clear();
	
	for (int i = 0; i < 6; i++) {
		g.AddNode();
	}
	
	g.AddEdge(3, 5, 7);
	g.AddEdge(0, 2, 4);
	g.AddEdge(2, 3, 2);
	g.AddEdge(0, 1, 1);
	g.AddEdge(1, 4, 7);
	g.AddEdge(3, 4, 1);
	g.AddEdge(0, 3, 1);
	g.AddEdge(2, 5, 1);
	g.AddEdge(2, 4, 4);
	
	g.Print();
	cout << endl;
	cout << "         (0) " << endl;
	cout << "        / | \\ " << endl;
	cout << "       /  |  \\ " << endl;
	cout << "      /   |   \\ " << endl;
	cout << "     1    4    1 " << endl;
	cout << "    /     |     \\ " << endl;
	cout << "   /      |      \\ " << endl;
	cout << "  /       |       \\ " << endl;
	cout << "(3)--2---(2)      (1) " << endl;
	cout << " |\\     / |       / " << endl;
	cout << " | 7   1  |      / " << endl;
	cout << " |  \\ /   |     / " << endl;
	cout << " \\  (5)   |    / " << endl;
	cout << "  1       4   7 " << endl;
	cout << "   \\_____ | _/ " << endl;
	cout << "         (4) " << endl;
	cout << endl;
	cout << "Running Kruskals Algorithm" << endl;
	el =  g.KruskalsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl << "Running Prims Algorithm" << endl;
	el =  g.PrimsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl << "Here I will show that both algorithms can handle negative weights" << endl;
	cout << "Setting up a new graph for the algorithms with negative weights..." << endl;
	g.Clear();
	
	for (int i = 0; i < 6; i++) {
		g.AddNode();
	}
	
	g.AddEdge(0, 1, 1);
	g.AddEdge(0, 2, 4);
	g.AddEdge(0, 3, 1);
	g.AddEdge(1, 4, 7);
	g.AddEdge(2, 3, 2);
	g.AddEdge(2, 4, -4);
	g.AddEdge(2, 5, 1);
	g.AddEdge(3, 4, 2);
	g.AddEdge(3, 5, -7);
	
	g.Print();
	cout << endl;
	cout << "         (0) " << endl;
	cout << "        / | \\ " << endl;
	cout << "       /  |  \\ " << endl;
	cout << "      /   |   \\ " << endl;
	cout << "     1    4    1 " << endl;
	cout << "    /     |     \\ " << endl;
	cout << "   /      |      \\ " << endl;
	cout << "  /       |       \\ " << endl;
	cout << "(3)--2---(2)      (1) " << endl;
	cout << " |\\     / |       / " << endl;
	cout << " |-7   1  |      / " << endl;
	cout << " |  \\ /   |     / " << endl;
	cout << " \\  (5)   |    / " << endl;
	cout << "  2      -4   7 " << endl;
	cout << "   \\_____ | _/ " << endl;
	cout << "         (4) " << endl;
	cout << endl;
	cout << "Running Kruskals Algorithm" << endl;
	el =  g.KruskalsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl << "Running Prims Algorithm" << endl;
	el =  g.PrimsAlgorithm();
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	cout << endl << "The algorithms do not always produce the same MST. The above Prim's algorithm was started at node 1. Below it is start at node 2." << endl;
	cout << endl << "Running Prims Algorithm" << endl;
	el =  g.PrimsAlgorithm(2);
	for (int i = 0; i < el.size(); i++) {
		el[i].Print();
		cout << endl;
	}
	
	return;
}

// TestEdgeClass
// Does tests on the public functions for the Edge class
void TestEdgeClass() {
	cout << " ---------- Testing the Edge class" << endl;
	
	cout << "Creating an edge to id 1 with a weight of 1..." << endl;
	Edge e(1, 1);
	
	cout << "Printing the edge class" << endl;
	e.Print();
	
	cout << endl;
	
	return;
}

// TestNodeClass
// Does tests on the public functions for the Node class
void TestNodeClass() {
	cout << " ---------- Testing the Node class" << endl;
	
	cout << "Creating a node with an id of 1..." << endl;
	Node n(1);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	cout << "Adding an edge (#1 with 12 weight) to the node..." << endl;
	n.AddEdge(1, 12);
	
	cout << "Adding an edge (#2 with 12 weight) to the node..." << endl;
	n.AddEdge(2, 12);
	
	cout << "Adding an edge (#3 with 6 weight) to the node..." << endl;
	n.AddEdge(3, 6);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	cout << "Checking the contains edge (2) function: ";
	if (n.ContainsEdge(2)) {
		cout << "true"  << endl;
	} else {
		cout << "false" << endl;
	}
	
	cout << "Checking the contains edge (6) function: ";
	if (n.ContainsEdge(6)) {
		cout << "true"  << endl;
	} else {
		cout << "false" << endl;
	}
	cout << endl;
	
	cout << "Removing an edge (3)... " << endl;
	n.RemoveEdge(3);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	cout << "Removing an edge (6)... " << endl;
	n.RemoveEdge(6);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	cout << "Update an edge endID (1 to 2)... " << endl;
	n.UpdateEdge(1, 2, true);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	cout << "Update an edge weight (1 to 5 wght)... " << endl;
	n.UpdateEdge(1, 1, false, 5.0);
	
	cout << "Printing the node class" << endl;
	n.Print();
	cout << endl;
	
	return;
}

void TestHeapClass() {
	Heap<int> heap;
	
	cout << "Testing the Push function" << endl;
	heap.Push(40);
	heap.Push(60);
	heap.Push(30);
	heap.Push(50); 
	heap.Print();
	
	heap.Push(70);
	heap.Push(50);
	heap.Push(45);
	heap.Print();
	
	heap.Push(32);
	heap.Print();
	
	heap.Push(25);
	heap.Print();
	
	cout << endl << "Testing the Pop function" << endl;
	heap.Pop();
	heap.Print();
	
	heap.Pop();
	heap.Print();
	
	heap.Pop();
	heap.Print();
	
	cout << "Front element: " << heap.Front() << endl;
	cout << "Heap size: " << heap.Size() << endl;
	
	cout << "Is the heap empty? ";
	if (heap.Empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	cout << "Empty cleared!" << endl;
	heap.Clear();
	
	cout << "Is the heap empty? ";
	if (heap.Empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	cout << "Heap size: " << heap.Size() << endl;
	
	return;
}

void TestUnionFindClass() {
	UnionFind uf(3);
	
	cout << "Current sets of elements 1 and 2..." << endl;
	cout << "1: " << uf.Find(1) << endl;
	cout << "2: " << uf.Find(2) << endl;
	
	cout << "Trying to merge 1 and 2... Successful?" << (uf.Union(1, 2) ? " Yes" : " No") << endl;
	
	cout << "Current sets of elements 1 and 2..." << endl;
	cout << "1: " << uf.Find(1) << endl;
	cout << "2: " << uf.Find(2) << endl;
	
	cout << "Trying to merge 1 and 2... Successful?" << (uf.Union(1, 2) ? " Yes" : " No") << endl;
	
	cout << endl;
	
	return;
}