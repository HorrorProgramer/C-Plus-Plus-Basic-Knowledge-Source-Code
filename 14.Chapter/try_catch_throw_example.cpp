#include <iostream>

using namespace std;

double division(int a, int b);

int main(int argc, const char *argv[]) {
	int x = 50, y = 2, z = 0;

	try {
		z = division(x, y);
		cout << z << endl;
	} catch (const char *msg) {
		cerr << msg << endl;
	}

	return 0;
}

double division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition!";
	}

	return (a / b);
}
