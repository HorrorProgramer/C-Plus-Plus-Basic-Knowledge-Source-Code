#include <iostream>
using namespace std;

class Box {
	public:
		double length;
		double breadth;
		double height;

		double getVolume(void);
		void setLength(double len);
		void setBreadth(double bre);
		void setHeight(double hei);
};

double Box::getVolume(void) {
	return length * breadth * height;
}

void Box::setLength(double len) {
	length = len;
}

void Box::setBreadth(double bre) {
	breadth = bre;
}

void Box::setHeight(double hei) {
	height = hei;
}

int main(int argc, const char *argv[]) {
	Box box1, box2;
	double volume = 0.0;

	box1.setLength(6.0);
	box1.setHeight(5.0);
	box1.setBreadth(7.0);

	box2.setLength(12.0);
	box2.setHeight(10.0);
	box2.setBreadth(13.0);

	volume = box1.getVolume();
	cout << "Box1 的体积: " << volume << endl;
	
	volume = box2.getVolume();
	cout << "Box2 的体积: " << volume << endl;

	return 0;
}
