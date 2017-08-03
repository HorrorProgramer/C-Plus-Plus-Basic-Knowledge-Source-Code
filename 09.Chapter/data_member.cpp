#include <iostream>
using namespace std;

class Box {
	public:
		double length;
		double breadth;
		double height;
};

int main(int argc, const char *argv[]) {
	Box box1;
	Box box2;
	double volume = 0.0;

	box1.height = 5.0;
	box1.length = 6.0;
	box1.breadth = 7.0;

	box2.height = 10.0;
	box2.length = 12.0;
	box2.breadth = 13.0;

	volume = box1.height * box1.length * box1.breadth;
	cout << "Box1的体积: " << volume << endl;

	volume = box2.height * box2.length * box2.breadth;
	cout << "Box2的体积: " << volume << endl;

	return 0;
}
