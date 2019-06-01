#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	string id;
	string name;
	int balance;
	static int sum;


	Account() {
		id = "00000";
		name = "awefawef";
		balance = 0;
	}
	Account(string id_, string name_, int balance_) {
		id = id_;
		name = name_;
		balance = balance_;
		sum += balance;
	}

	string getId() {
		return id;
	}
	string getName() {
		return name;
	}
	int getBalance() {
		return balance;
	}
	int getStaticInt() {
		return sum;
	}
	~Account() {
		
	}

};

bool checkId(string id, Account acnt);

int Account::sum = 0;

int main() {
	int num=0, balance;
	string id, name;

	cout << "총 학생 수 입력 : ";
	cin >> num;
	Account *acnt;

	acnt = new Account[num];

	for (int i = 0; i < num; i++) {
		cout << i+1 << "번째 학생 계좌 입력 : 학번 : ";
		cin >> id;
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				if (checkId(id, acnt[j]) == true) {
					cout << "중복된 학번을 입력하셨습니다. 프로그램을 종료합니다.";
					exit(0);
				}
			}
		}
		cout << endl << "이름 : ";
		cin >> name;

		cout << endl << "잔액 : ";
		cin >> balance;

		cout << "====================" << endl;

		acnt[i] = Account(id, name, balance);
	}

	
	
	delete[] acnt;
	cout << "회수된 금액 총액 : " << acnt[2].getStaticInt() << endl;
}

bool checkId(string id, Account acnt) {
	if (id == acnt.getId()) {
		return true;
	}
	else {
		return false;
	}
}