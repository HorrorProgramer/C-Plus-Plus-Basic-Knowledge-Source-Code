#include <iostream>

using namespace std;

class PrintData {
	public:
		void print(int i) {
			cout << "Printing int: " << i << endl;
		}

		void print(double f) {
			cout << "Printing float: " << f << endl;
		}

		void print(char* c ) {
			cout << "Printing character: " << c << endl;
		}
};

int main(int argc, const char *argv[]) {
	PrintData print;

	print.print(5);
	print.print(500.263);
	print.print("Hello World!");

	return 0;
}
