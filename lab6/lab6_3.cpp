#include <iostream>
using namespace std;

int fibonacci(int);

int main() {
	int n;
	int* p;

	cout << "n : ";
	cin >> n;

	// 1
	p = new int[n];
	// 2
	for (int i = 0; i < n; i++) {
		p[i] = fibonacci(i+1);
	}
	// 3
	for (int i = 0; i < n; i++) {
		cout << p[i] << "	";
	}
	cout << endl;
	// 4
	delete[] p;
}

int fibonacci(int n) {
	if (n != 1 && n != 2) {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	else if (n == 1) {
		return 0;
	}
	else {
		return 1;
	}
	
}