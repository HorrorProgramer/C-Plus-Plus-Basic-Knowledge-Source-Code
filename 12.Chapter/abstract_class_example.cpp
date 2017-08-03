#include <iostream>

using namespace std;

class Shape {
	protected:
		int width, height;

	public:
		Shape(int w = 0, int h = 0);
		virtual int getArea() = 0;
		void setWidth(int w);
		void setHeight(int h);
};

Shape::Shape(int w, int h): width(w), height(h) {}

void Shape::setWidth(int w) {
	width = w;
}

void Shape::setHeight(int h) {
	height = h;
}

class Rectangle: public Shape {
	public:
		Rectangle(int a = 0, int b = 0);
		int getArea() {
			return (width * height);
		}
};

Rectangle::Rectangle(int a, int b): Shape(a, b) {}

class Triangle: public Shape {
	public:
		Triangle(int a = 0, int b = 0);
		int getArea() {
			return (width * height / 2);
		}
};

Triangle::Triangle(int a, int b): Shape(a, b) {}

int main(int argc, const char *argv[]) {
	Rectangle rect(5, 10);

	cout << "Rect area: " << rect.getArea() << endl;

	Triangle tri(5, 10);
	
	cout << "Tri area: " << tri.getArea() << endl;
	return 0;
}
