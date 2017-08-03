#include <iostream>

using namespace std;

class Shape {
	protected:
		int width, length;

	public:
		Shape(int a = 0, int b = 0);
		virtual int area();
};

Shape::Shape(int a, int b): width(a), length(b) {}

int Shape::area() {
	cout << "Parent class area" << endl;
	return 0;
}

class Rectangle: public Shape {
	public:
		Rectangle(int a = 0, int b = 0);
		int area();
};

Rectangle::Rectangle(int a, int b): Shape(a, b) {}
int Rectangle::area() {
	cout << "Rectangle class area: " << endl;
	return (width * length);
}

class Triangle: public Shape {
	public:
		Triangle(int a = 0, int b = 0);
		int area();
};

Triangle::Triangle(int a, int b): Shape(a, b) {}
int Triangle::area() {
	cout << "Triangle class area: " << endl;
	return (width * length / 2);
}

int main(int argc, const char *argv[]) {
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	shape = &rec;
	shape->area();

	shape = &tri;
	shape->area();

	return 0;
}
