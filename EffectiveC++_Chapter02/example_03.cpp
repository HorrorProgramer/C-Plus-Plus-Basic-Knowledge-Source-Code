
#include <iostream>

using namespace std;

class Uncopyable{
	protected:
		Uncopyable();
		~Uncopyable();

	private:
		Uncopyable(const Uncopyable&);
		Uncopyable& operator= (const Uncopyable&);
};

class HomeForSale: private Uncopyable {
	
};

int main(int argc, const char* argv[]) {
	HomeForSale h1;
	HomeForSale h2(h1);

	return 0;
}
