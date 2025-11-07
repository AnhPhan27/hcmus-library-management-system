#include "utils.h"
#include <limits>

using namespace std;

void discardLine() {
    cin.clear();
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;
    }
}

// Hiển thị thông báo "Nhan Enter de tiep tuc..." và chờ người dùng nhấn Enter.
void waitForEnter() {
    cout << "Nhan Enter de tiep tuc...";
    string tmp;
    getline(cin, tmp);
}
