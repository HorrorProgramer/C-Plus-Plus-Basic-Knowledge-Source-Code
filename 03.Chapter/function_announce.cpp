#include <iostream>
using namespace std;

int sum(int a, int b);

int main(int argc, const char *argv[]) {
	int a = 10;
	int b = 20;

	cout << sum(a, b) << endl;
	
	return 0;
}

int sum(int a, int b) {
	return a + b;
}
