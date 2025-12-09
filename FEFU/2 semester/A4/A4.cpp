#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
const int LETTER_BUCKETS = 52;

int index(char ch){
    if (ch <= 'Z') {
        return ch - 'A';          
    } 
    return ch - 'a' + 26;    
}


void bucket_sort(vector<string>& words, int pos){

    vector<string> buckets[LETTER_BUCKETS]; 

    // Раскладываем слова по корзинам
    for (int i = 0; i < words.size(); ++i){
        int idx = index(words[i][pos]);
        buckets[idx].push_back(words[i]);
    }
    
    // Собираем слова обратно 
    int k = 0;
    for (int i = 0; i < LETTER_BUCKETS; ++i){
        for (int j = 0; j < buckets[i].size(); ++j){
            words[k] = buckets[i][j];
            ++k;
        }
    }
}

int main() {
    ifstream fin("input.txt");

    int N;
    fin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i){
        fin >> words[i];
    }

    bucket_sort(words, 2); 
    bucket_sort(words, 1); 
    bucket_sort(words, 0); 

    ofstream fout("output.txt");
    for (int i = 0; i < N; ++i){
        fout << words[i] << endl;
    }

    return 0;
}
