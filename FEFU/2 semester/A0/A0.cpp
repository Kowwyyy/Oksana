#include <fstream>
using namespace std;

int main(){
    ifstream fin("input.txt");
    int N, x, y, start, end, maxm = 0;
    fin >> N;
    int m[100]= {0};

    for (int i = 0; i < N; i++){

        fin >> x >> y;
        start = (x - y < 0 ) ? 0 : (x - y);
        end = (x + y > 100) ? 100 : (x + y);

        for (int j = start; j < end; j++){
            m[j]++;
            maxm = (maxm < m[j]) ? m[j] : maxm;
        }
    }
    ofstream fout("output.txt");
    fout << maxm;
}