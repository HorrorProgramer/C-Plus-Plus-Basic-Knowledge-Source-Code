#include <iostream>

using namespace std;

class WebBrowser {
    public:
       void clearCache();
       void clearHistory();
       void removeCookies();
  //member 函数
       void excuteAllFunction();
};

WebBrowser::excuteAllFunction() {
    clearCache();
    clearHistory();
    removeCookies();
}

// non-member 函数
void clearWebBrowserAll(const WebBrowser& wb) {
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

int main(int argc, const char *argv[]) {
    return 0;
}
