#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
	string name;
	int id;
	string department;
	int grade;
	int credit;
public:
	Student(string n = "default", unsigned int i = 0, string d = "default", int g = 0, int c = 0) : name(n), id(i), department(d), grade(g), credit(c) {}
	string getName();
	int getId();
	string getDepartment();
	int getGrade();
	int getCredit();
	void setName(string);
	void setId(int);
	void setDepartment(string);
	void setGrade(int);
	void setCredit(int);
	virtual void print();
};

string Student::getName() { return name; }
int Student::getId() { return id; }
string Student::getDepartment() { return department; }
int Student::getGrade() { return grade; }
int Student::getCredit() { return credit; }
void Student::setName(string name_) { name = name_; }
void Student::setId(int id_) { id = id_; }
void Student::setDepartment(string department_) { department = department_; }
void Student::setGrade(int grade_) { grade = grade_; }
void Student::setCredit(int credit_) { credit = credit_; }
void Student::print() {
	cout << "I'm student" << endl << endl;
}

class UnderGraduate : public Student {
private:
	string Circles;
public:
	UnderGraduate(string n , unsigned int i , string d , int g , int c, string cir) : Student(n,i,d,g,c), Circles(cir) {}
	void print();
};

void UnderGraduate::print() {
	cout << setw(50) << setfill('=') << "" << endl;
	cout << "이    름 : " << getName() << endl;
	cout << "학    번 : " << getId() << endl;
	cout << "소속학과 : " << getDepartment() << endl;
	cout << "학    년 : " << getGrade() << endl;
	cout << "이수학점 : " << getCredit() << endl;
	cout << "동아리명 : " << Circles << endl;
	cout << setw(50) << setfill('=') << "" << endl;
}

class Graduate : public Student {
private:
	bool type;
	double Scholarship;
public:
	Graduate(string n, unsigned int i, string d, int g, int c, bool type_, double Scholarship_) : Student(n,i,d,g,c), type(type_), Scholarship(Scholarship_) {}
	void print();
};

void Graduate::print() {
	string type_;
	if (type)
		type_ = "교육조교";
	else
		type_ = "연구조교";
		
	cout << setw(50) << setfill('=') << "" <<endl;
	cout << "이    름 : " << getName() << endl;
	cout << "학    번 : " << getId() << endl;
	cout << "소속학과 : " << getDepartment() << endl;
	cout << "학    년 : " << getGrade() << endl;
	cout << "이수학점 : " << getCredit() << endl;
	cout << "조교유형 : " << type_ << endl;
	cout << "장학비율 : " << Scholarship << endl;
	cout << setw(50) << setfill('=') << "" << endl;
}

int main(void) {
	Student Std;
	Graduate Kang("강석원", 2018311025, "컴퓨터공학과", 1, 18, false, 0.5);
	UnderGraduate Hong("홍길동", 20141111, "컴퓨터공학과", 2, 80, "알고리즘동아리");

	Std.print();
	Kang.print();
	Hong.print();

	return 0;
}