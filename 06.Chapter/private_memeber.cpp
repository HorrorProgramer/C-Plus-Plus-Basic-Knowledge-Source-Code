#include <iostream>
using namespace std;

class Box {
	public:
		double length;
		void setWidth(double wid);
		double getWidth(void);

	private:
		double width;
};

double Box::getWidth(void) {
	return width;
}

void Box::setWidth(double wid) {
	width = wid;
}

int main(int argc, const char *argv[]) {
	Box box;

	box.length = 10.0;
	cout << "Length of Box: " << box.length << endl;

	box.setWidth(10.0);

	cout << "Width of Box: " << box.getWidth() << endl;

	return 0;
}
