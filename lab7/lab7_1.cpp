#include <iostream>
#include <string>
using namespace std;


class User {
public:
	string id;
	string password;

	void setIdpass(string id_, string password_) {
		this->id = id_;
		this->password = password_;
	}

	 string getId() const{
		return id;
	}

	 string getPassword() const {
		 return password;
	 }
};


bool check_id(string id_, User user);
bool check_password(string password_, User user);

int main() {
	User user[3];
	string id, password, searchId, searchPassword;

	for (int i = 0; i < 3; i++) {
		cout << "========== " << i + 1 << " ==========" << endl;
		cout << "id : ";
		cin >> id;
		
		if (i != 0) {
			int count = 0;
			for (int j = 0; j < i; j++) {
				if (check_id(id, user[j]) == false) {
					cout << "이미 존재하는 ID입니다." << endl;
					cout << "종료합니다." << endl;
					exit(0);
					break;
				}
				count += 1;
				
			}

			if (count == i) {
				
			}
			else {
				break;
			}
			
		}

		cout << "password : ";
		cin >> password;
		
		cout << "=======================" << endl << endl;
		user[i].setIdpass(id, password);
	}

	while (1) {
		cout << "========== Login ==========" << endl << endl;
		cout << "Id : ";
		cin >> searchId;
		if (searchId == "종료") {
			cout << "종료하겠습니다.";
			break;
		}
		cout << "Password : ";
		cin >> searchPassword;
		int count = 0;
		for (int i = 0; i < 3; i++) {
			if (check_id(searchId, user[i]) == false) {
				if (check_password(searchPassword, user[i]) == false) {
					break;
				}
			}
			count += 1;

		}
		if (count == 3) {
			cout << "잘못된 ID이거나 PASSWORD 입니다." << endl;
		}
		else {
			cout << "로그인 되셨습니다." << endl;
		}

		cout << "=========================" << endl;
	}
	
}

bool check_id(string id_, User user) {
	if (user.getId() == id_) {
		return false;
	}
	else {
		return true;
	}
}

bool check_password(string password_, User user) {
	if (user.getPassword() == password_) {
		return false;
	}
	else {
		return true;
	}
}