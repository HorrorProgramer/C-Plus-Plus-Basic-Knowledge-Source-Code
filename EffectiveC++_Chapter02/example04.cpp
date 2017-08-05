#include <iostream>

using namespace std;

class Widget {
	public:
		Widget& operator= (const Widget& rhs);
};

Widget& Widget:operator= (const Widget& rhs) {
	return *this;
}

int main(int argc, const char *argv[]) {
	

	return 0;
}
