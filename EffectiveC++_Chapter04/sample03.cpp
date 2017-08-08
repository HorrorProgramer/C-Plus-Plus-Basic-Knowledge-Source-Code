#include <iostream>

using namespace std;

class Rational {
    public:
        Rational(int numerator = 0, int denominator = 1);

    private:
        int n, d;
  friend Rational operator* (const Rational& lhs, const Rational& rhs);
};

int main(int argc, const char *argv[]) {
  return 0;
}
