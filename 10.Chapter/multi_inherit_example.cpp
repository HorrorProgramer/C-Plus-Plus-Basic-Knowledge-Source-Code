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

class PaintCost {
	public:
		int getCost(int area) {
			return area * 70;
		}
};

class Rectangle: public Shape, public PaintCost {
	public:
		int getArea() {
			return width * height;
		}
};

int main(int argc, const char *argv[]) {
	Rectangle rect;
	int area = 0;

	rect.setWidth(5);
	rect.setHeight(7);
	area = rect.getArea();

	cout << "Area is: " << area << endl;
	cout << "Total Cost is: " << rect.getCost(area) << endl;

	return 0;
}
