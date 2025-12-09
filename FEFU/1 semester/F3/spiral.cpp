#include <fstream>
#include <vector>
using namespace std;

int main() {
    int N;
    ifstream fin("input2.txt");
    fin >> N;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    int num = N * N; 
    int T = 0, B = N - 1, L = 0, R = N - 1;  

    while (num >= 1) {
        
        for (int i = L; i <= R; i++) { // сверху слева направо
            matrix[T][i] = num--;
        }
        T++;

        for (int i = T; i <= B; i++) { // справа сверху вниз
            matrix[i][R] = num--;
        }
        R--;

        for (int i = R; i >= L; i--) { // снизу справа на лево
            matrix[B][i] = num--;
        }
        B--;

        for (int i = B; i >= T; i--) { // слева снизу вверх
            matrix[i][L] = num--;
        }
        L++;
    }
    ofstream fout("output2.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
