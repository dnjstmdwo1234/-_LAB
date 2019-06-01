#include <iostream>
#include <list>
using namespace std;

int command() {
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
	cin >> num;

	return num;
}

template <typename T>
class CList {
public:
	CList() : m_Length(0) {}
	~CList() {}

	bool lsEmpty() {
		if (m_Length == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool lsFull() {
		if (m_Length == 5) {
			return true;
		}
		else {
			return false;
		}
	}

	void Add(T data) {
		for (int i = 0; i < 5; i++) {
			if (data == m_Array[i]) {
				cout << "중복된 데이터가 존재" << endl;
				break;
			}
			if (i == 4) {
				m_Array[m_Length] = data;
				m_Length += 1;
				for (int i = 0; i < m_Length; i++) {
					if (m_Array[i] > m_Length) {
						int temp = m_Array[m_Length - 1];
						m_Array[m_Length - 1] = m_Array[i];
						m_Array[i] = temp;
					}
				}
			}
		}
		
	}

	void Delete(T data) {
		for (int i = 0; i < 5; i++) {
			if (data == m_Array[i]) {
				cout << "해당 데이터를 삭제합니다 : " << m_Array[i] << " : 배열의 " << i <<  " 번째" << endl;
				if (i == 4) {
					m_Array[4] = NULL;
				}
				else {
					int j = i;

					while (m_Array[j] != NULL) {
						m_Array[j] = m_Array[j + 1];
						j += 1;
					}
				}
				

				break;
			}

			if (i == 4) {
				cout << "해당 데이터가 array에 없습니다." << endl;
			}
		}
	}

	void Print() {
		cout << "* Current List" << endl;
		for (int i = 0; i < m_Length; i++) {
			cout << m_Array[i] << " ";
		}
		cout << endl;
	}

private:
	T m_Array[5];
	int m_Length;
};


int main() {
	CList<int> list;
	int input;
	int com;
	while (1) {
		com = command();
		switch (com) {
		case 1:
			if (list.lsFull() == 1) {
				cout << "List가 가득차있습니다." << endl;
				break;
			}
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2:
			cout << "\n삭제할 데이터 : ";
			if (list.lsEmpty() == 1) {
				cout << "List 가 비어있습니다." << endl;
				break;
			}
			cin >> input;
			list.Delete(input);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << "\n\t프로그램을 종료합니다.\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}