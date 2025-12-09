#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double N, a = 0;
    long long n;
    cin >> N;
    n = (sqrt(8 * N + 1) - 1) / 2;
    if (sqrt(N * 8 + 1) == int(sqrt(N * 8 + 1))) {
        cout << 1;
        return 0;
    }
    for (long long i = n; i > 0; i--) {
        a = N - (i * (i + 1) / 2);
        if (sqrt(a * 8 + 1) == int(sqrt(a * 8 + 1))) {
            cout << 2;
            return 0;
        }
    }
    cout << 3;
}