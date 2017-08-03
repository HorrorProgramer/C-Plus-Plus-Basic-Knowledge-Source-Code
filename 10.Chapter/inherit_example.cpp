#include <iostream>

using namespace std;

class Shape {
	public:
		void setWidth(int w) {
			width = w;
		}

		void setHeight(int h) {
			height = h;
		}

	protected:
		int width;
		int height;
};

class Rectangle: public Shape {
	public:
		int getArea() {
			return width * height;
		}
};

int main(int argc, const char *argv[]) {
	Rectangle rect;

	rect.setWidth(10);
	rect.setHeight(5);

	cout << "Total Area Is: " << rect.getArea() << endl;

	return 0;
}
