#include "Dijkstra.h"


Dijkstra::Dijkstra() {}
Dijkstra::~Dijkstra()
{
}
void Dijkstra::DFS(int node) {
	free[node] = false;
	Path[nodeCount] = node;
	nodeCount++;
	for (int v = 0; v < n; v++)
		if (mat[node][v] != 0 && free[v])
		{
			lenght += mat[node][v];
			DFS(v);
		}
	if (nodeCount == 5 && mat[node][0] != 0) {
		THEREISAPATH = true;
		checkMinPath();
	}
	free[node] = true;
	Path[nodeCount] = 0;	
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
		lenght += mat[Path[i-1]][Path[i]];
	lenght += mat[Path[n-1]][0];
	if (lenght < minLength || minLength == 0) {
		minLength = lenght;
		for (int i = 0;i < n;i++)
			minPath[i] = Path[i];
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
		cout << 1 << "\n Tong quang duong: " << minLength << endl;
	}
	else
		cout << "Qua den!!!Khong ton tai duong di.";
}
