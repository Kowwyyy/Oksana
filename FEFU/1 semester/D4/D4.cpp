#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int N, tmp;
    int a[2001] = {0};
    ifstream fin("input.txt");
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> tmp;
        a[tmp + 1000] += 1;
    }
    
    ofstream fout("output.txt");
    for (int i = 0; i < 2001; i++) {
        if (a[i] == 0) {
            continue;
        }
        else {
            fout << (i - 1000) << " " << a[i];
        }
        fout << "\n";
    }
}
