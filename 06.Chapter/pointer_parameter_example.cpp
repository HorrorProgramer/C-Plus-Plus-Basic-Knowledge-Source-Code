#include <iostream>
#include <ctime>

using namespace std;

void getSecond(unsigned long *p);

int main(int argc, const char *argv[]) {
	unsigned long time = 0;

	getSecond(&time);

	cout << "Second is :" << time << endl;

	return 0;
}

void getSecond(unsigned long *p) {
	*p = time(NULL);
	
	return;
}
