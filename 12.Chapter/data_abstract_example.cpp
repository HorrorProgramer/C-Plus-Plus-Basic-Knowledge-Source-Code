#include <iostream>

using namespace std;

class Adder {
	public:
		Adder(int i = 0);
		void addNum(int number);
		int getTotal();

	private:
		int total;
};

Adder::Adder(int i): total(i) {}

void Adder::addNum(int number) {
	total += number;
}

int Adder::getTotal() {
	return total;
}

int main(int argc, const char *argv[]) {
	Adder a;

	a.addNum(10);
	a.addNum(20);
	a.addNum(30);

	cout << "Total: " << a.getTotal() << endl;

	return 0;
}
