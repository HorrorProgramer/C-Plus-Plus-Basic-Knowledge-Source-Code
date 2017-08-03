#include <iostream>

using namespace std;

class Box {
	public:
		double getVolume() {
			return length * breadth * height;
		}

		void setLength(double len) {
			length = len;
		}

		void setBreadth(double bre) {
			breadth = bre;
		}

		void setHeight(double hei) {
			height = hei;
		}

		Box operator+(const Box& b) {
			Box box;
			box.length = b.length + this->length;
			box.breadth = b.breadth + this->breadth;
			box.height = b.height + this->height;
			return box;
		}

	private:
		double length;
		double breadth;
		double height;
};

int main(int argc, const char *argv[]) {
	Box box1, box2, box3;
	double volume = 0.0;

	box1.setLength(5.0);
	box1.setBreadth(7.0);
	box1.setHeight(6.0);

	box2.setLength(12.0);
	box2.setBreadth(13.0);
	box2.setHeight(10.0);

	volume = box1.getVolume();
	cout << "Box1's volume is: " << volume << endl;

	volume = box2.getVolume();
	cout << "Box2's volume is: " << volume << endl;

	box3 = box1 + box2;
	
	volume = box3.getVolume();
	cout << "Box3's volume is: " << volume << endl;

	return 0;
}
