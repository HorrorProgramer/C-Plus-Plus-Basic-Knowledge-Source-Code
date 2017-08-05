#include <iostream>

using namespace std;

template <class T> class HomeForSale {
	private:
		HomeForSale(const HomeForSale<T>&);
		HomeForSale& operator= (const HomeForSale<T>&);

	public:
		HomeForSale();
};

template <class T>
HomeForSale<T>::HomeForSale() {}

int main(int argc, const char* argv[]) {
	HomeForSale<int> h1;
	HomeForSale<int> h2(h1);

	return 0;
}
