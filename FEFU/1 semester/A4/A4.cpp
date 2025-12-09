#include <iostream>
#include <cstring>
using namespace std;

int main() {
    float y;
    int x, exp;

    cin >> y;
    memcpy(&x, &y, sizeof(float));
    exp = (x >> 23) & 0xFF;

    if (exp != 0) {
        cout << (exp - 127);
    } 
    else {
        if (y == 0) {
            cout << 0;
        } 
        else {
            cout << -126;
        }
    }
    return 0;
}
