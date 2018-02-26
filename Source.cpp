#include"Dijkstra.h"
int main() {
	Dijkstra a;
	int input;
	cout << "nhap diem bat dau: ";
	cin >> input;
	a.convertMatrix();
	if (a.checkInput() == true) {
		a.DFS(input-1);
		a.releasePath();
	}
	else
		cout << "Qua den!!!Khong ton tai duong di qua tat ca cac thanh pho\n";
	return 0;
}