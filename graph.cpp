//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS

// default constructor
Graph::Graph()
{
	n = 0;
	numEdges = 0;
	budget = 0.0;
	values = new float[n];
	for (int x = 0; x < n; x++)
		values[x] = 0.0;

	// intialize graph matrix 2D array
	matrix = new int*[n];

	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int c = 0; c < n; c++)
		for (int r = 0; r < n; r++)
			matrix[r][c] = 0;
}

// constructor with two arguments representing the number of nodes, initial budget
Graph::Graph(int rno, float rbudget)
{
	n = rno;
	numEdges = 0;
	budget = rbudget;

	// initialize values array
	values = new float[n];

	for (int x = 0; x < n; x++)
		values[x] = 0.0;

	// intialize graph matrix 2D array
	matrix = new int*[n];

	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int c = 0; c < n; c++)
		for (int r = 0; r < n; r++)
			matrix[r][c] = 0;
}

void Graph::reset(int rno, float rbudget)
{
	n = rno;
	numEdges = 0;
	budget = rbudget;

	// initialize values array
	values = new float[n];

	for (int x = 0; x < n; x++)
		values[x] = 0.0;

	// intialize graph matrix 2D array
	matrix = new int*[n];

	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int c = 0; c < n; c++)
		for (int r = 0; r < n; r++)
			matrix[r][c] = 0;
}

// adds an edge between two nodes in the graph node1 and node2
void Graph::addEdge(int node1, int node2)
{
	matrix[node1][node2] = 1;
	matrix[node2][node1] = 1;
	numEdges++;
}

// sets a value for a node
void Graph::setValue(int node, float rval)
{
	values[node] = rval;
}

// sets the intial budget
void Graph::setBudget(float rbu)
{
	budget = rbu;
}

// return number of nodes
int Graph::getNSize()
{	
	return n;
}

// return number of edges
int Graph::getESize()
{
	return numEdges;
}

// return current budget
float Graph::getBudget()
{
	return budget;
}

// returns the value of the node
float Graph::getValue(int node)
{
	return values[node]; // ERROR?
}

// reads data from a specified file
void Graph::readData(string fileName)
{
	fstream file;
	int num, temp = 0;
	int counter = 0;

	file.open(fileName);

	// read first line and set as NODES
	file >> num;
	cout << num << endl;
	n = num;
	// read second line and set as BUDGET
	file >> num;
	cout << num << endl;
	setBudget((float)num);

	// fill object
	reset(n, budget);

	// read third line and set as VALUES
	for(int i = 0; i < n; i++)
	{
		file >> num;
		cout << num << " ";
		setValue(i, (float)num);
	}
	cout << endl;

	// read rest of lines and set as EDGES
	while (!file.eof())
	{
		file >> num;
		file >> temp;
		addEdge(num, temp);
		cout << num << " " << temp << endl;
	}
	file.close();
}

//return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive
int Graph::DFS(int startNode)
{
	stack<int> s;

	return 0;
}

// return the starting node that gives a longest DFS run before running out of budget
// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph::bestStartVertex()
{
	return 0;
}
