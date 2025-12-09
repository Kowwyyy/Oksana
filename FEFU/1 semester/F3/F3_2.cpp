#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, r;
    ifstream fin("input2.txt");
    fin >> N >> r;
    vector <long long> miay(N, 0);
    long long num = pow(N, 2);
    int T = 0, B = N - 1, L = 0, R = N - 1;  

    while (num >= 1) {
        
        for (int i = L; i <= R; i++) { // сверху слева направо
            if (T == r - 1){
                miay[i] = num;     
            }
            num--;
        }
        T++;

        for (int i = T; i <= B; i++) { // справа сверху вниз
            if (i == r - 1){
                miay[R] = num;
                num = num - (B - i + 1);
                break;
            }
            num--;
        }
        R--;

        for (int i = R; i >= L; i--) { // снизу справа на лево
            if (B == r - 1 ){
                miay[i] = num;
            }
            num--;
        }
        B--;

        for (int i = B; i >= T; i--) { // слева снизу вверх
            if (i == r - 1){
                miay[L] = num;
                num -= i - T + 1  ;
                break;
            }
            num--;
        }
        L++;
    }
    ofstream fout("output2.txt");
    for (int i = 0; i < N; i++) {
        fout << miay[i] << " ";
    }
    return 0;
}
