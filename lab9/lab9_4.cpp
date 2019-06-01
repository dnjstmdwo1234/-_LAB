#include <iostream>
using namespace std;

class Stack {
private:
	int* p_list;
	int size;
	int MAX_SIZE;
public:
	Stack(int _MAX_SIZE = 1000) :MAX_SIZE(_MAX_SIZE), size(0) {
		p_list = new int[MAX_SIZE];
	}
	~Stack() {
		delete[] p_list;
	}

	int find_index(int _item) {
		for (int i = 0; i < size; i++) {
			if (p_list[i] == _item) {
				return i;
			}
			if (i == size - 1) {
				return -1;
			}
		}
		
	}

	void push(int _item) {
		if (find_index(_item) == -1) {
			if (size > MAX_SIZE) {
				cout << "Error : out of memory" << endl;
			}
			else {
				p_list[size] = _item;
				size += 1;
			}
		}
	}

	int pop() {
		if (size == 0) {
			cout << "Error: No item exist in the list" << endl;
		}
		size -= 1;
		return p_list[size];
	}

	void print() const {
		cout << "Items in the list : ";
		for (int i = 0; i < size; i++) {
			cout << get_item(i) << ", ";
		}
		cout << endl;
	}

	int get_size() { return size; }
	int get_item(int _index) const { return p_list[_index]; }

	void operator +=(Stack& s_) {
		for (int i = 0; i < s_.size; i++) {
			push(s_.p_list[i]);
		}
	}

	bool operator ==(Stack& s_) {
		for (int i = 0; i < s_.size; i++) {
			for (int j = 0; j < size; j++) {
				if (p_list[j] != s_.p_list[i]) {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	Stack s1, s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(1);
	s2.push(2);
	s2.push(5);

	s1.print();
	s2.print();

	s1 += s2;

	s1.print();
	s2.print();
	cout << "s1 == s2 ? " << (s1 == s2) << endl;

	s1.pop();

	s1.pop();
	s2.pop();

	s2.pop();
	s2.pop();
	cout << "s1 == s2 ? " << (s1 == s2) << endl;

	return 0;
}