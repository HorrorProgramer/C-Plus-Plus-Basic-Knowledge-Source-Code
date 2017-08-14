#include <iostream>
#include <string.h>
#include <ctype.h>
#include "StackTP.h"

using namespace std;

int main(int argc, const char *argv[]) {
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add a purchase order. \n"
         << "P to process a PO, or Q to quit. \n";

    while (cin >> ch && toupper(ch) != 'Q') {
      while (cin.get() != '\n') {
        continue;
      }

      if (!isalpha(c)) {
        cout << "\a";
        continue;
      }

      
    }
    return 0;
}
