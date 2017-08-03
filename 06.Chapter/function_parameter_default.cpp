#include <iostream>

using namespace std;

int sum(int a, int b = 10) {
	return a + b;
}

int main(int argc, const char *argv[]) {
	int a = 20;

	cout << "Sum Value is: " << sum(20) << endl;

	return 0;
}


