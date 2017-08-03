#include <iostream>

using namespace std;

class Box {
	double length;
	double breadth;
	double height;

	public:
		double getVolume();
		void setLength(double len);
		void setBreadth(double bre);
		void setHeight(double hei);
		Box operator+(const Box& b);
};

double Box::getVolume() {
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

Box Box::operator+(const Box& b) {
	Box box;

	box.length = b.length + this->length;
	box.breadth = b.breadth + this->breadth;
	box.height = b.height + this->height;

	return box;
}

int main(int argc, const char *argv[]) {
	Box box1, box2, box3;
	double volume = 0.0;

	box1.setLength(5);
	box1.setBreadth(7);
	box1.setHeight(5);

	box2.setLength(12);
	box2.setBreadth(13);
	box2.setHeight(10);

	volume = box1.getVolume();
	cout << "Box1's Volume: " << volume << endl;
	
	volume = box2.getVolume();
	cout << "Box2's Volume: " << volume << endl;

	box3 = box1 + box2;
	volume = box3.getVolume();
	cout << "Box3's Volume: " << volume << endl;

	return 0;
}
