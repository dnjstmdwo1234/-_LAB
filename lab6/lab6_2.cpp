#include <iostream>
using namespace std;

class CStudent {
public:
	int number;
	string name;
	string major;

	CStudent() {
		number = 0;
		name = "abcd";
		major = "abcd";
	}
	CStudent(const int number_, string name_, string major_) {
		number = number_;
		name = name_;
		major = major_;
	}
	void Display() {
		cout << "학번 : " << number << endl;
		cout << "이름 : " << name << endl;
		cout << "전공 : " << major << endl;
		cout << endl;
	}

	void setNumber(int number_) {
		this->number = number_;
	}
	void setName(string name_) {
		this->name = name_;
	}
	void setMajor(string major_) {
		this->major = major_;
	}
	int getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
};

bool check_id(int id_, CStudent s);


int main() {
	CStudent s[3];
	int inputNumber;
	string inputName, inputMajor;
	int length = 0;

	while (1) {
		for (int i = 0; i < 3; i++) {
			length += 1;
			cout << i + 1 << " 번째 학생 입력" << endl;
			cout << "학번 : ";
			cin >> inputNumber;
			cout << "이름 : ";
			cin >> inputName;
			cout << "전공 : ";
			cin >> inputMajor;
			if (i != 0) {
				for (int j = 0; j < i; j++) {
					if (check_id(inputNumber, s[j]) == true) {
						cout << "*중복되는 학번이 존재합니다." << endl << endl;
						i = i - 1;
						break;
					}
					else {
						continue;
					}
				}
			}

			if (length - i != 1) {
				length -= 1;
				continue;
			}

			else {
				s[i] = CStudent(inputNumber, inputName, inputMajor);
				cout << "*입력 완료" << endl << endl;
			}
			
		}
		if (length == 3) {
			cout << "입력을 마쳤습니다. 프로그램을 종료합니다";
			exit(0);
		}
	}

	return 0;
}

bool check_id(int id_, CStudent s) {
	if (id_ == s.getNumber()) {
		return true;
	}
	else {
		return false;
	}
}

