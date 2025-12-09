#include <iostream>
#include <vector>

using namespace std;

int fibCash[100] = {0};

int fib(int n){
    if (n <= 1) return n;
    if (fibCash[n]>0) return fibCash[n]; // 643 = 64 + 3 
    else{
        fibCash[n] = fib(n-1) + fib (n-2);
        return fibCash[n];
    }
    
}
    
int main (){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    for (int i; i<100; i++){
        cout << fibCash[i] << " ";
    }
    
}