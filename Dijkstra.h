#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

class Dijkstra
{
private:
	int n;
	int from;
	int to;
	int mat[50][50];// Graph
	int Path[50];
	int minPath[50];
	bool free[50];
	int minLength=0;
	int nodeCount = 0;
	int lenght = 0;
	int THEREISAPATH = false;
public:
	Dijkstra();
	void DFS(int node);
	~Dijkstra();
	void checkMinPath();
	void convertMatrix();
	bool checkInput();
	void releasePath();

};

