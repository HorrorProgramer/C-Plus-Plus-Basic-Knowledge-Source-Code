#include <iostream>

using namespace std;

template <class T> class NamedObject {
    string nameValue;
    T objectValue;

    public:
        NamedObject(const char *name, const T& value);
        NamedObject(const string& name, const T& value);
        string getNameValue();
};

template  <class T>
string NamedObject<T>::getNameValue() { return  nameValue; }

template <class T>
NamedObject<T>::NamedObject(const char *name, const T& value): nameValue(name), objectValue(value) {}

template <class T>
NamedObject<T>::NamedObject(const string& name, const T& value): nameValue(name), objectValue(value) {}

int main(int argc, const char *argv[]) {
    NamedObject<int> na1("Smallest Prime Number", 2);
    NamedObject<int> na2(na1);

    cout << "Na1 Name: " << na1.getNameValue() << "Na2 Name: " << na2.getNameValue() << endl;

    return 0;
}
