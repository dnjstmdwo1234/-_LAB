#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(char voca1, vector<char> arr1) {
	for (int j = 0; j < arr1.size(); j++) {
		if (voca1 == arr1[j]) {
			return true;

		}
		
	}
	return false;
}


int main() {
	string voca1, voca2;
	vector<char> arr1,arr2;
	vector<int> count1,count2;
	int delete_ = 0, a=0;

	cout << "두 단어를 입력해주세요. : ";
	cin >> voca1 >> voca2;

	for (int i = 0; i < voca1.length(); i++) {
		if (i == 0) {
			arr1.push_back(voca1[i]);
			count1.push_back(1);
		}
		else {
			if (check(voca1[i], arr1)) {
				for (int j = 0; j < arr1.size(); j++) {
					if (voca1[i] == arr1[j]) {
						count1[j] += 1;
					}
				}


			}
			else {
				arr1.push_back(voca1[i]);
				count1.push_back(1);
			}
		}

	}

	for (int i = 0; i < voca2.length(); i++) {
		if (i == 0) {
			arr2.push_back(voca2[i]);
			count2.push_back(1);
		}
		else {
			if (check(voca2[i], arr2)) {
				for (int j = 0; j < arr2.size(); j++) {
					if (voca2[i] == arr2[j]) {
						count2[j] += 1;
					}
				}


			}
			else {
				arr2.push_back(voca2[i]);
				count2.push_back(1);
			}
		}

	}

	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2.size(); j++) {
			if (arr1[i] == arr2[j]) {
				if (count1[i] == count2[j]) {
					a = 1;
					break;
				}
				else if (count1[i] > count2[j]) {
			
					delete_ += count1[i] - count2[j];
					a = 1;
					break;
				}
				else {
					
					delete_ += count2[j] - count1[i];
					a = 1;
					break;
				}
			}
		}
		if (a == 0) {
			delete_ += count1[i];
		}
		a = 0;

	}
	for (int i = 0; i < arr2.size(); i++) {
		for (int j = 0; j < arr1.size(); j++) {
			if (arr2[i] == arr1[j]) {
				a = 1;
				break;
			}
		}
		if (a == 0) {
			delete_ += count2[i];
		}
		a = 0;
	}
	cout << delete_ << endl;
}