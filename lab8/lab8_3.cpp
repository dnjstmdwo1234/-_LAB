#include <iostream>
#include <string>

using namespace std;

class Train {
public:
	Train() {}
	Train(int people) {
		mPeople = people;
	}
	~ Train() {}

	virtual int station(int takeOff, int takeOn) {
		this->mPeople = mPeople - takeOff + takeOn;
		return mPeople;
	}

protected:
	int mPeople;
};

class Ktx :public Train {
public:
	Ktx() : Train(0) {}
	Ktx(int people) : Train(people) {}
	
	~Ktx() {}

	int station(int takeOff, int takeOn) {
		this->mPeople = mPeople - takeOff + takeOn;
		return mPeople;
	}

	int getPeople() {
		return mPeople;
	}
};

int main() {
	int in, out, max, current;
	
	Ktx k;
	k = Ktx();
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번역 : ";
		cin >> out >> in;
		if (i == 0) {
			out = 0;
		}
		else if (i == 4) {
			in = 0;
		}
		else {}
		k.station(out, in);
		current = k.getPeople();
		if (current > 300) {
			cout << "정원 초과입니다.";
			exit(0);
		}
		else if (current < 0) {
			cout << "정원 미달입니다.";
			exit(0);
		}
		else {}

		if (i == 0) {
			max = current;
		}
		else {
			if (max > current) {
				continue;
			}
			else {
				max = current;
			}
		}
	}


	cout << "가장 많은 사람이 탑승 했을 때의 사람 수 = " << max << endl;



	return 0;
}