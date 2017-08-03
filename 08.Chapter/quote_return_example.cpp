#include <iostream>

using namespace std;

int num[] = {0, 1, 2, 3, 4, 5};
int& getNum(int i);

int main(int argc, const char *argv[]) {
	cout << "Before Change Value is" << endl;

	for (int i = 0; i < 6; i++) {
		cout << "num["<< i <<"] = " << num[i] << endl;;
	}

	getNum(2) = 3;
	getNum(3) = 4;

	cout << "After Change Value is" << endl;	
	for (int i = 0; i < 6; i++) {
		cout << "num["<< i <<"] = " << num[i] << endl;
	}

	return 0;
}

int& getNum(int i) {
	return num[i];
}
