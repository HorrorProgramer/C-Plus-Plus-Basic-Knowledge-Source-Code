#include <iostream>

using namespace std;

class PrettyMenu {
    public:
        void changeBackground(istream& imgSrc);
    private:
        Mutex mutex;
        Image* bgImage;
        int imageChanges;
};

void PrettyMenu::changeBackground(istream& imgSrc) {
  lock(&mutex);
  delete bgImage;
  ++imageChanges;
  bgImage = new Image(imgSrc);
  unlock(&mytes);
}

int main(int argc, const char* argv[]) {
  return 0;
}
