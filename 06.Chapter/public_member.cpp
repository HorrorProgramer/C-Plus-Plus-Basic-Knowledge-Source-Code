#include <iostream>
using namespace std;

class Line {
	public:
		double length;
		void setLength(double len);
		double getLength(void);
};

double Line::getLength(void) {
	return length;
}

void Line::setLength(double len) {
	length = len;
}

int main(int argc, const char *argv[]) {
	Line line;

	line.setLength(6.0);

	cout << "Length of line: " << line.getLength() << endl;

	line.length = 10.0;

	cout << "Length of line: " << line.getLength() << endl;

	return 0;
}
