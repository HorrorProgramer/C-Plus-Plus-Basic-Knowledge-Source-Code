#include <iostream>

using namespace std;

class Distance {
	private:
		int feet;
		int inches;

	public:
		Distance();
		Distance(int f, int in);
		void displayDistance();
		Distance operator-();
};

Distance::Distance() {
	feet = 0;
	inches = 0;
}

Distance::Distance(int f, int in):feet(f), inches(in) {
	cout << "Constructor Method Using" << endl;
}

void Distance::displayDistance() {
	cout << "Feet: " << feet << "Inches: " << inches << endl;
}

Distance Distance::operator-() {
	feet = -feet;
	inches = -inches;
	
	return Distance(feet, inches);
}

int main(int argc, const char *argv[]) {
	Distance D1(11, 10), D2(-5, 11);

	-D1;
	D1.displayDistance();

	-D2;
	D2.displayDistance();

	return 0;
}
