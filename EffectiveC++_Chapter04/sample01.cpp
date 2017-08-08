#include <iostream>

using namespace std;

struct Day {
  int day;
  explicit Day(int val): day(val) {}
};
/*
struct Month {
  int month;
  explicit Month(int val): month(val) {}
};
*/
class Month {
    private:
        explicit Month(int m);

    public:
        static Month Jan() { return Month(1) };
};

struct Year {
  int year;
  explicit Year(int val): year(val) {}
};

class Date {
  int day = 0;
  int month = 0;
  int year = 0;

  public:
  Date(const Month&, const Day&, const Year&);
};

Date::Date(const Month& month, const Day& day, const Year& year): month(month), day(day), year(year) {}

int main(int argc, const char *argv[]) {
  Date(Month::Jan(), )

    return 0;
}
