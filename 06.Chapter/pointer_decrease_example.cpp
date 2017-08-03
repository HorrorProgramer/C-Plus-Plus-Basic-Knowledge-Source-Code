#include <iostream>

using namespace std;

const int iMax = 10;

int main(int argc, const char *argv[]) {
	int num[iMax] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = &num[iMax - 1];

	for (int i = iMax - 1; i > 0; i--) {
		cout << "Address of num["<< i <<"] =" << p << endl;
		cout << "Value of num["<< i <<"] =" << *p << endl;
		p--;
	}

	return 0;
}
