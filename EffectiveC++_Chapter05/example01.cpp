#include <iiostream>

using namespace std;

const int MininumPasswordLength = 6;
string encryptPassword(const string& password);

int main(int argc, const char* argv[]) {
  return 0;
}

string encryptPassword(const string& password) {
  if (password.length() < MininumPasswordLength) {
    throw logic_error("Password is too short!");
  }

  string encrypted(password);
  encrypt(encrypted);

  return encrypted;
}

void encrypt(const string& str) {
  
}
