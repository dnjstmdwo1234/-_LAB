#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


int main() {
	srand((unsigned int)time(0));
	int max = 0,min = 100;
	vector<int> vector1(10);
	vector<int>::iterator iter1 = vector1.begin();
	vector<int> vector2(10);
	vector<int>::iterator iter2 = vector2.begin();

	for (int i = 0; i < 10; i++) {
		vector1[i] = rand() % 11;
		vector2[i] = rand() % 21;
	}
	cout << "vector1" << endl;
	for (int i = 0; i < 10; i++) {
		cout << iter1[i] << " ";
	}
	cout << endl;

	cout << "vector2" << endl;
	for (int i = 0; i < 10; i++) {
		cout << iter2[i] << " ";
	}
	cout << endl;
	
	for (iter1 = vector1.begin(); iter1 != vector1.end(); iter1++) {
		for (iter2 = vector2.begin(); iter2 != vector2.end(); iter2++) {
			if (max <= *iter1 * *iter2) {
				max = *iter1 * *iter2;
			}
			if (min >= *iter1 * *iter2) {
				min = *iter1 * *iter2;
			}
		}
	}
	cout << "최대값 : " << max << endl;
	cout << "최솟값 : " << min << endl;

}