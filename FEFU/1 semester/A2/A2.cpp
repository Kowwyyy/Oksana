#include <iostream>
#include <cstdint>
using namespace std;

int main(){

    uint64_t n;
    cin >> n;
    bool f = 0;
    
    while(n > 0) {
        if(((n ^ 0xBABE) << 48) == 0){
            cout << "YES";
            return 0;
        }
        n = n >> 4;
    }
    cout << "NO";
    return 0;
}
