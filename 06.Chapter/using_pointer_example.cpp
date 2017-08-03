#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
	int var = 20;
	int *ip = &var;

	cout << "Var Value is: " << var << endl;
	cout << "Var Address is: " << ip << endl;
	cout << "IP Value is: " << *ip << endl;

	return 0;
}
