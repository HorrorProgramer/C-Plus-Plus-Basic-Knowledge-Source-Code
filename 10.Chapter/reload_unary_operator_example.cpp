#include <iostream>

using namespace std;

class Time {
	private:
		int hours;
		int minutes;
		
	public:
		Time();
		Time(int h, int m);
		void displayTime();
		Time operator++();
		Time operator++(int);
};

Time::Time() {
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m):hours(h), minutes(m) {
	cout << "Constructor Method is using " << endl;
}

void Time::displayTime() {
	cout << "H: " << hours << "M: " << minutes << endl;
}

Time Time::operator++() {
	++minutes;

	if (minutes > 60) {
		++hours;
		minutes -= 60;
	}

	return Time(hours, minutes);
}

Time Time::operator++(int) {
	Time T(hours, minutes);

	
	++minutes;
	if (minutes > 60) {
		++hours;
		minutes -= 60;
	}

	return T;
}

int main(int argc, const char *argv[]) {
	Time T1(11, 59), T2(20, 40);

	++T1;
	T1.displayTime();
	++T1;
	T1.displayTime();

	++T2;
	T2.displayTime();
	++T2;
	T2.displayTime();

	return 0;
}
