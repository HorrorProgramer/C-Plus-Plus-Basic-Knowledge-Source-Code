#include <iostream>
using namespace std;

class Box {
	protected:
		double width;
};

class SmallBox: public Box {
	public:
		void setSmallWidth(double wid);
		double getSmallWidth(void);
};

void SmallBox::setSmallWidth(double wid) {
	width = wid;
}

double SmallBox::getSmallWidth(void) {
	return width;
}

int main(int argc, const char *argv[]) {
	SmallBox box;

	box.setSmallWidth(10.0);
	cout << "Width of box: " << box.getSmallWidth() << endl;

	return 0;
}
