#include <iostream>
#include <cmath>
using namespace std;

template <typename T>

class Point {
	T x1;
	T y1;
	T x2;
	T y2;
	T r;
public:
	void setPointFromKeybord() {
		cout << "첫번째 x : ";
		cin >> x1;
		cout << "첫번째 y : ";
		cin >> y1;
		cout << "두번째 x : ";
		cin >> x2;
		cout << "두번째 y : ";
		cin >> y2;
		r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}

	void print() {
		cout << "두점 사이의 거리 = " << r << endl;
	}
};

int main() {
	Point<double> p;
	p.setPointFromKeybord();
	p.print();

	return 0;


}