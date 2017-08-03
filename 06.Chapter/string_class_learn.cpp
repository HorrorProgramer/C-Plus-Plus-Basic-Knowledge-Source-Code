#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
	string str1 = "Hello", str2 = "World", str3;
	int size = 0;

	str3 = str1 + str2;
	cout << "Str3 is: " << str3 << endl;

	size = str3.size();
	cout << "Str3 size: " << size << endl;

	str3 = str2;
	cout << "Str3 Copy is: " << str3 << endl;

	return 0;
}
