#include <iostream>
#include <string>
using namespace std;

class Account {
	
public:
	string name;
	string id;
	int balance;

	Account(string name_, string id_, int balance_) {
		name = name_;
		id = id_;
		balance = balance_;
	}
	string getName() {
		return name;
	}

	string getId() {
		return id.substr(0,4);
	}

	int getBalance() {
		return balance;
	}

	Account operator + (Account const& acnt) {
		Account result(this->name, this->id, this->balance + acnt.balance);
		return result;
	}
	Account operator - (Account const& acnt) {
		Account result(this->name, this->id, this->balance - acnt.balance);
		return result;
	}
	Account operator = (Account const& acnt) {
		this->balance = acnt.balance;
		return (*this);
	}
	
};

ostream& operator << (ostream& cout, Account const& acnt) {
	cout << "보낸 학생의 잔액 : " << "학번 : " << acnt.id << "	이름 : " << acnt.name << "	잔액 : " << acnt.balance;
	return cout;
}

bool search(string num, Account acnt);

int main() {
	Account acnt[3]{
		Account("신은섭", "2019204212", 10000),
		Account("김유민", "2012311060", 0),
		Account("이강호", "2011102214", 5000),
	};

	string give, receive;
	while (true) {
		int a = 0, b = 0, count1 = 0, count2 = 0;
		cout << "돈을 보낼 학생의 학번을 입력하세요. : ";
		cin >> give;
		if (give == "종료") {
			cout << acnt[0] << endl;
			cout << acnt[1] << endl;
			cout << acnt[2] << endl;
			exit(0);
		}
		cout << "돈을 받을 학생의 학번을 입력하세요. : ";
		cin >> receive;
		if (give == receive) {
			cout << "돈을 보낼학생과 받는 학생이 일치합니다. 다시 입력해 주세요." << endl;
			continue;
		}

		for (int i = 0; i < 3; i++) {
			if (search(give, acnt[i]) == true) {
				a = i;
				break;
			}
			count1 += 1;
		}
		for (int i = 0; i < 3; i++) {
			if (search(receive, acnt[i]) == true) {
				b = i;
				break;
			}
			count2 += 1;
		}
		
		if (count1 == 3 || count2 == 3) {
			cout << "돈을 보낼학생 혹은 돈을 받는 학생의 학번이 존재하지 않습니다. 다시 입력해 주세요." << endl;
			continue;
		}

		if (acnt[a].getBalance() == 0) {
			cout << "보낼 학생의 잔액이 0 입니다. 다시입력해 주세요." << endl;
			continue;
		}
		acnt[b] = acnt[a] + acnt[b];
		acnt[a] = acnt[a] - acnt[a];
		

		cout << acnt[a] << endl;
		cout << acnt[b] << endl;
	}
}

bool search(string num, Account acnt) {
	if (num == acnt.getId()) {
		return true;
	}
	
	else {
		return false;
	}
}