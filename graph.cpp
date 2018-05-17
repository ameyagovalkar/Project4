//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include "graph.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS

Graph::Graph() // default constructor
{
	n = 0;
	budget = 0;
	edges = 0;
	vis = 0;
	vertices = 0;
	//visited = new bool[n];
	//values = new float[n];
	//adj = new int*[n];

	/*
	for (int i = 0; i < n; i++)
	{
		adj[i] = new int[n];
	}*/

	for (int x = 0; x < n; x++)
	{
		visited[x] = false;
	}

	/*
	for (int x = 0; x < n; x++)
	{
		values[x] = 0.0;
	}
	*/
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			adj[i][j] = 0;
		}
	}
	*/
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	n = rno;
	budget = rbudget;
	edges = 0;
	vis = 0;
	vertices = 0;
	//visited = new bool[n];
	//values = new float[n];
	//adj = new int*[n];


	for (int x = 0; x < n; x++)
	{
		visited[x] = false;
	}

	for (int x = 0; x < n; x++)
	{
		values[x] = 0.0;
	}

	/*
	for (int i = 0; i < n; i++)
		adj[i] = new int[n];

	for (int c = 0; c < n; c++)
		for (int r = 0; r < n; r++)
			adj[c][r] = 0;
*/
}

void Graph::addEdge(int node1, int node2) // adds an edge between two nodes in the graph node1 and node2
{/*
	if (node1 > n || node2 > n || node1 < 0 || node2 < 0)
	{
		cout << "Invalid edge!\n";
	}
	else
	{*/
	/*
	adj[node1][node2] = 1;
	adj[node2][node1] = 1;
	
	edges++;
	//}*/

	if (adj[node1][node2] != true && adj[node2][node1] != true) {
		adj[node1][node2] = true;
		adj[node2][node1] = true;
		edges++;
	}
}

void Graph::setValue(int node, float rval) // sets a value for a node
{
	values[node] = rval;
}

void Graph::setBudget(float rbu) // sets the initial budget
{
	budget = rbu;
}

int Graph::getNSize() // return number of nodes
{
	return n;
}

int Graph::getESize() // return number of edges
{
	return edges;
}

float Graph::getBudget() // return current budget
{
	return budget;
}

float Graph::getValue(int node) // returns the value of the node
{
	return values[node];
}

void Graph::reset(int rno, float rbudget)
{
	n = rno;
	edges = 0;
	vis = 0;
	budget = rbudget;

	for (int i = 0; i < n; i++)
		visited[i] = false;

	// initialize values array
	//values = new float[n];

	for (int x = 0; x < n; x++)
		values[x] = 0.0;

	// intialize graph matrix 2D array
	//adj = new int*[n];
	/*
	for (int i = 0; i < n; i++)
		adj[i] = new int[n];
		
	for (int c = 0; c < n; c++)
		for (int r = 0; r < n; r++)
			adj[c][r] = 0;
	*/

}

void Graph::readData(string fileName) // reads data from a specified file
{/*
	fstream file;
	int num = 0;
	float budget = 0.0;
	int temp = 0;
	int counter = 0;

	file.open(fileName);

	// read first line and set as NODES
	file >> num;
	cout << num << endl;
	n = num;
	// read second line and set as BUDGET
	file >> budget;
	cout << budget << endl;
	setBudget(budget);

	// fill object
	reset(n, budget);

	// read third line and set as VALUES
	for (int i = 0; i < n; i++)
	{
		file >> budget;
		cout << budget << " ";
		setValue(i, budget);
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
	*/

	int i = 0;
	ifstream myfile;
	myfile.open(fileName);
	myfile >> n;
	myfile >> budget;
	for (i = 0; i < n; i++)  // setting values for each node
	{
		myfile >> values[i];
	}
	//int l, j;
	//while (!myfile.eof());
	//{
	//	myfile >> l >> j;
	//	addEdge(l, j);
	//}
	for (i = 0; !myfile.eof(); i++)		// setting adjacency
	{
		int l, j;
		myfile >> l >> j;
		//if (m[l][j] == false && m[j][l] == false) {
		//	m[l][j] = true;
		//	m[j][l] = true;
		//}
		addEdge(l, j);
	}
	myfile.close();
}

void Graph::DFS_(int startNode) //return the number of nodes visited using DFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{
	/*
	visited[startNode] = true;

	if (budget > values[startNode])
	{
		budget = budget - values[startNode];
	}
	else
	{
		
		return 0;
	}
	

	for (int i = 0; i < n; i++)
	{
		if (adj[startNode][i] == 1)
		{
			if (visited[i] != true)
			{
				//vis++;
				return 1 + DFS_(i);
			}
		}
	}
	

	return 0;
	*/

	if (tempBudget <= 0)
		return;
	visited[startNode] = true;
	tempBudget = tempBudget + values[startNode];
	//int v = 1;
	/*if(budget > 0)*/
	for (int x = 0; x < n; x++) {
		//if (tempbudget <= 0)
		//	break;

		if (adj[startNode][x] == true && visited[x] == false) {
			DFS_(x);
		}

	}


}

int Graph::DFS(int startVertex)
{
	//reset(n, budget);
	//return DFS_(startVertex);

	for (int i = 0; i < n; i++)
		visited[i] = false;

	tempBudget = budget;

	DFS_(startVertex);
	int l = 0;
	for (int x = 0; x < n; x++)
		if (visited[x] == true)
			l++;

	return l;
}

						// return the starting node that gives a longest DFS run before running out of budget
						// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph::bestStartVertex()
{
	int max_Node = 0; // hold the name of the Node holding the maximum value

	for (int i = 0; i < n; i++)
		if (DFS(max_Node) < DFS(i))
			max_Node = i;

	return max_Node;
}
