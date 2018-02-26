#include "Dijkstra.h"


Dijkstra::Dijkstra() {}
Dijkstra::~Dijkstra()
{
}
void Dijkstra::DFS(int node) {
	free[node] = false;
	Queue[nodeCount] = node;
	nodeCount++;
	/*cout << "Queue: ";
	for (int i = 0; i < nodeCount;i++)
		cout << Queue[i] << " ";
	cout << endl;*/
	for (int v = 0; v < n; v++)
		if (mat[node][v] != 0 && free[v])
		{
			lenght += mat[node][v];
			DFS(v);
		}
	if (nodeCount == 5 && mat[node][Queue[0]] != 0) {
		THEREISAPATH = true;
		checkMinPath();
	}
	free[node] = true;
	Queue[nodeCount] = 0;	
	nodeCount--;
}
void Dijkstra::convertMatrix() {
	fstream fin("input.txt");
	int input;
	fin >> n;
	for (int i = 0;i < n;i++)
		free[i] = true;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			mat[i][j] = 0;
	while (!fin.eof())
	{	
		fin >> from;
		fin >> to;
		fin >> input;
		mat[from - 1][to - 1] = mat[to - 1][from - 1] = input;
	}
	cout << "Matrix:\n";
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << mat[i][j]<<" ";
		cout << endl;
	}
	cout << "--------Load input completed-------" << endl;
	fin.close();
}
void Dijkstra::checkMinPath() {
	lenght = 0;
	for (int i = 1;i < n;i++)
		lenght += mat[Queue[i-1]][Queue[i]];
	lenght += mat[Queue[n-1]][Queue[0]];
	if (lenght < minLength || minLength == 0) {
		minLength = lenght;
		for (int i = 0;i < n;i++)
			minPath[i] = Queue[i];
	}

}
bool Dijkstra::checkInput(){
	bool out = true;
	for (int i = 0;i < n;i++)
	{
		int count = 0;
		for (int j = 0;j < n;j++)
		{
			if (mat[i][j] != 0)
				count++;
		}
		if (count < 2)
		{
			out = false;
			break;
		}
	}
	return out;
}
void Dijkstra::releasePath() {
	if (THEREISAPATH)
	{
		cout << "Quang duong thoa man: ";
		for (int i = 0;i < n;i++)
			cout << minPath[i] + 1 << "-->";
		cout << Queue[0]+1 << "\n Tong quang duong: " << minLength << endl;
	}
	else
		cout << "Qua den!!!Khong ton tai duong di.";
}
