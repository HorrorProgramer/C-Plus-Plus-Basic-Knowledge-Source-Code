#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	/*
	 *This source be used to show how to use the annotation
	 * 
	 *This li multi line annotation
	 *
	 * */
	
	cout << "HelloWorld!"; //This is line annotation

	/*
	 *Block annotation
	 * */
#if 1
	cout << "This is block annotation";
#endif

	return 0;
}

