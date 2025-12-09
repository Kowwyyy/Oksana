#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    string inp;
    int k = 0, kmax = 0;
    stack<char> st;
    cin >> inp;

    for (char c : inp) {
        if (c == '[' || c == '{' || c == '(') {
            st.push(c);
            k += 1;
            kmax = max(kmax, k);
        } else if (!st.empty() && ((st.top() == '{' && c == '}') || (st.top() == '[' && c == ']') || (st.top() == '(' && c == ')'))) {
            st.pop();
            k -= 1;
        } else {
            cout << -1;
            return 0;
        }
    }
    if (st.empty()) {
        cout << kmax;
    } else {
        cout << -1;
    }

    return 0;
}
