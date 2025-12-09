#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int N, M, l, r;
    ifstream fin("input.txt");
    fin >> N;

    int a[N + 1] = {0}; 
    for (int i = 1; i <= N; ++i) {
        fin >> a[i];
    }

    int s[N + 1] = {0};
    for (int i = 1; i <= N; ++i) {
        s[i] = s[i - 1] + a[i];
    }

    fin >> M;
    ofstream fout("output.txt");

    for (int i = 0; i < M; ++i) {
        fin >> l >> r;
        fout << (s[r] - s[l - 1]) << " ";
    }

    return 0;
}
