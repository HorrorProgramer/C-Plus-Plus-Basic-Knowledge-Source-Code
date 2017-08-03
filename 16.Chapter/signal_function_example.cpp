#include <iostream>
#include <csignal>

using namespace std;

void signalHandler(int signum) {
	cout << "Interupt signal ("<< signum <<") received.\n" << endl;
	exit(signum);
}

int main(int argc, const char *argv[]) {
	signal(SIGINT, signalHandler);

	while(1) {
		cout << "Going to sleep..." << endl;
		sleep(1);
	}

	return 0;
}
