#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main(int argc, const char *argv[]) {
	int a = 100;
	int b = 200;

	cout << "a value is: " << a << endl;
	cout << "b value is: " << b << endl;

	swap(a, b);

	cout << "a value is: " << a << endl;
	cout << "b value is: " << b << endl;

	return 0;
}


void swap(int& a, int& b) {
	int m = a;

	a = b;
	b = m;

	return;
}
