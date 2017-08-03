#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[]) {
	char data[100] = "";
	ofstream outfile;

	outfile.open("test.rtf");
	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);

	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();

	outfile << data << endl;

	outfile.close();
	
	ifstream inputfile;
	
	inputfile.open("test.rtf");
	cout << "Reading from file" << endl;
	inputfile >> data;
	cout << data << endl;

	inputfile >> data;
	cout << data << endl;

	inputfile.close();

	return 0;
}
