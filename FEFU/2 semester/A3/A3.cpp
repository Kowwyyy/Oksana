#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long long merge_sort(vector<float>& arr, int left, int right, vector<float>& temp) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long inv_count = 0;

    inv_count += merge_sort(arr, left, mid, temp);
    inv_count += merge_sort(arr, mid + 1, right, temp);

    // cлияние двух отсортированных половин
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {

        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // копируем остатки левой части
    while (i <= mid) temp[k++] = arr[i++];
    // копируем остатки правой части
    while (j <= right) temp[k++] = arr[j++];

    // копируем обратно в исходный массив
    for (int x = left; x <= right; ++x) {
        arr[x] = temp[x];
    }

    return inv_count;
}

int main() {
    ifstream fin("input.txt");
    int N;
    string name;
    fin >> N;
    vector<float> heights(N);
    for (int i = 0; i < N; ++i) {
        fin >> heights[i] >> name;
    }

    vector<float> temp(N);
    long long swaps = merge_sort(heights, 0, N - 1, temp);

    ofstream fout("output.txt");
    fout << swaps;

    return 0;
}
