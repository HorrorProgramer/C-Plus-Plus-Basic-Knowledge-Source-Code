#include <iostream>
using namespace std;

void fi() {
	#define N 12
	const int n = 12;
}

int main(int argc, const char *argv[]) {
	fi();
	cout << N << endl;
	/*cout << n << endl;
	 *error: use of undeclared identifier 'n'
	 * */
	
	return 0;
}

