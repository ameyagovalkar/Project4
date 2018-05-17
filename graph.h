//
//  graph.h
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class Graph {
public:

	Graph(); // default constructor
	Graph(int rno, float rbudget); // constructor with two arguments representing the number of nodes, initial budget
	
	void addEdge(int node1, int node2); // adds an edge between two nodes in the graph node1 and node2
	void setValue(int node, float rval); // sets a value for a node
	void setBudget(float rbu); // sets the initial budget
	int getNSize(); // return number of nodes
	int getESize(); // return number of edges
	float getBudget(); // return current budget
	float getValue(int node); // returns the value of the node
	void readData(string fileName); // reads data from a specified file
	int DFS(int startNode); //return the number of nodes visited using DFS starting at startNode and accumulating values at each node, as long as the budget remains positive
	void DFS_(int currentNode);
	void reset(int rno, float rbudget);
	// return the starting node that gives a longest DFS run before running out of budget
	// if there are multiple nodes with the same DFS run length, return the smallest node
	int bestStartVertex();

private:
	// member variables and helper functions (if needed)
	int n;
	float values[100];
	bool adj[100][100];
	int vis;
	bool visited[100];
	float budget;
	float tempBudget;
	int edges;
	int vertices;
	
};


#endif /* Graph_h */
