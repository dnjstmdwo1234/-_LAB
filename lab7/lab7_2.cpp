#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	int x;
	int y;

	Point() {
		x = 0;
		y = 0;
	}

	Point(int x_, int y_) {
		x = x_;
		y = y_;
	}

	Point operator - (Point const& pt) {
		Point result(this->x - pt.x, this->y - pt.y);
		return result;
	}

	Point operator * (Point const& pt) {
		Point result(this->x * pt.x, this->y * pt.y);
		return result;
	}

	Point operator = (Point const& pt) {
		this->x = pt.x;
		this->y = pt.y;
		return (*this);
	}

	void setPoint(int x_, int y_) {
		this->x = x_;
		this->y = y_;
	}

	double getPoint() {
		return sqrt(x + y);
	}
};


int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "첫번째 좌표(x1,y1)을 입력하세요 : ";
	cin >> x1 >> y1;

	cout << "두번째 좌표(x2,y2)을 입력하세요 : ";
	cin >> x2 >> y2;


	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);

	pP3 = new Point();

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);


	cout << "두 좌표 사이의 길이는 " << pP3->getPoint() << " 입니다." << endl;

	return 0;
}