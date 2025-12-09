#include <iostream> 
#include <ctime>
#include <cstdlib> 
#include <chrono>
#include <vector>

using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int n = 1000;
    vector<int> arr(n);
    
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = rand();
    }
    auto start = chrono::high_resolution_clock::now();

    bubble_sort(arr.data(), n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << duration.count();
    return 0;
}