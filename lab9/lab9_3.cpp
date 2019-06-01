#include <iostream>
using namespace std;

bool startGame(int input[], int answer[]) {
	int strike = 0, ball = 0;
	int a = 0;
	do {
		a = 0;
		cout << "1 ~ 9 범위의 숫자 세개를 입력해주세요 : ";
		for (int i = 0; i < 3; i++) {
			cin >> answer[i];
			if (answer[i] > 9) {
				a = 1;
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = i+1; j < 3; j++) {
				if (answer[i] == answer[j]) {
					a = 1;
				}
			}
		}
	} while (a == 1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (answer[i] == input[j]) {
				if (i == j) {
					strike += 1;
				}
				else {
					ball += 1;
				}
			}
		}
	}

	if (strike == 3) {
		return true;
	}
	else if (strike == 0 && ball == 0) {
		cout << "Out!!" << endl;
		return false;
	}
	else {
		cout << "Strike : " << strike << "\tBall : " << ball << endl;
		return false;
	}
}

int main() {
	int input[3];
	int answer[3];
	int a = 0, in;

	for (int i = 0; i < 3; i++) {
		in = rand() % 9 + 1;
		if (i == 0) {
			input[i] = in;
		}
		else {
			for (int j = 0; j < i; j++) {
				if (input[j] == in) {
					a = 1;
					break;
				}
			}
		}
		if (a == 0) {
			input[i] = in;
			a = 0;
		}
		
	}
	
	for (int i = 0; i < 9; i++) {
		if (startGame(input, answer)) {
			a = 1;
			break;
		}
	}
	
	if (a == 1) {
		cout << "정답입니다!" << endl;
	}
	else {
		cout << "패배했습니다." << endl;
		cout << "정답은 " << input[0] << " " << input[1] << " " << input[2] << " 입니다." << endl;
	}
}
