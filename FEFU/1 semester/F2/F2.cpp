#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, maxN = 0;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            maxN = max(maxN, A[i][j]);
        }
    }

    vector<vector<int>> B(N, vector<int>(maxN + 1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            B[i][A[i][j]]++;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= maxN; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
