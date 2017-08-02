#include <iostream>
using namespace std;

typedef int numType;

enum time {
	first = 0,
	second,
	third,
	forth,
	fifth
};

int main(int argc, const char *argv[]) {
	numType i = 3;
	enum time a = forth;

	if (a == forth)
		cout << "The i's is:" << sizeof(i) << endl;
		cout << "Successed!" << endl;

#if 0
	enum days {
		one,
		two,
		three
	} day;

	day = one;
	switch (day) {
		case one:
			cout << "one" << endl;
			break;
		case two:
			cout << "two" << endl;
			break;
		case three:
			cout << "three" << endl;
			break;
	}
#endif	
	return 0;
}


