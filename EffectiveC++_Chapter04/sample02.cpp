#include <iostream>

using namespace std;

class Person {
    public:
       Person();
       virtual ~Person();

    private:
       string name;
       string address;
};

class Student: public Person {
    public:
       Student();
       ~Student();

    private:
      string schoolName;
      string schoolAddress;
};



int main(int argc, const char *argv[]) {
  

  return 0;
}
