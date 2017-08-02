#include <iostream>
using namespace std;

extern int a, b, c;
extern float f;

int main(int argc, const char *argv[]) {
	int a = 10, b = 20, c;
	float f;
	
	c = a + b;
	cout << c << endl;

	f = 70.0 / 3.0;
	cout << f << endl;

	return 0;
}


