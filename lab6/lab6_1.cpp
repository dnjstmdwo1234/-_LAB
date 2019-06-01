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

int main() {
	CStudent s1;
	s1.Display();

	CStudent s2(1999000000, "공지철", "연극영화과");
	s2.Display();

	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 : " << s1.getNumber() << endl;
	cout << "이름 : " << s1.getName() << endl;
	cout << "전공 : " << s1.getMajor() << endl;

	return 0;
}

