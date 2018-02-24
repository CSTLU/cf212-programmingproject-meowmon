#include"Dijkstra.h"
int main() {
	Dijkstra a;
	a.convertMatrix();
	if (a.checkInput() == true) {
		a.DFS(0);
		a.releasePath();
	}
	else
		cout << "Qua den!!!Khong ton tai duong di qua tat ca cac thanh pho\n";
	return 0;
}