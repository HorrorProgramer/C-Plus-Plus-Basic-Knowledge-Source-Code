#include <iostream>

using namespace std;

const int iMax = 3;

int main(int argc, const char *argv[]) {
	int num[iMax] = {100, 200, 300};
	int *p = num;

	for (int i = 0; i < iMax; i++) {
		cout << "Address of num ["<< i <<"] =" << p << endl;
		cout << "Value of num ["<< i <<"] =" << *p << endl;
		p++;
	}

	return 0;
}
