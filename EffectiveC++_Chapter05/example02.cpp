#include <iostream>

using namespace std;

class Point {
    public:
      Point(int x, int y);
      void setX(int val);
      void setY(int val);
};

struct RectData {
  Point ulhc;
  Point lrhc;
};

class Rectangle {
    public:
  Point& upperLeft() const {return pData->ulhc;}
  Point& lowerRight() const {return pData->lrhc;}
    private:
       std::trl::shared_ptr<RectData> pData;
};

int main(int argc, const char *argv[]) {
  return 0;
}
