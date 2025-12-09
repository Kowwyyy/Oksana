#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void quick_sort(int arr[], int L, int R) {
    int i = L, j = R;
    int M = arr[(L + R) / 2];

    while (i <= j) {
        while (arr[i] < M) i++;      
        while (arr[j] > M) j--;      

        if (i <= j) {
            swap(arr[i], arr[j]);        
            i++;
            j--;
        }
    }

    if (L < j) quick_sort(arr, L, j);
    if (i < R) quick_sort(arr, i, R);
}

int main() {
    ifstream fin("input.txt");
    int N, L;
    fin >> N >> L;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        fin >> a[i];
    }

    quick_sort(a.data(), 0, N - 1);

    int finish_time = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            finish_time = a[i] + L;
        } else {
            finish_time = max(finish_time + L, a[i] + L);
        }
    }
    
    ofstream fout("output.txt");
    fout << finish_time << endl;
    return 0;
}
