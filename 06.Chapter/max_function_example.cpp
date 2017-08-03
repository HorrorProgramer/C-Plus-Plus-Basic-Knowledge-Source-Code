#include <iostream>
using namespace std;

int max(int a, int b);

int main(int argc, const char *argv[]) {
	int a = 10, b = 30;

	cout << "Max Number is: " << max(a, b) << endl;

	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}
