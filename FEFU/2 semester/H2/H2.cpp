#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int B, G, TB, TG;
    ifstream fin("input.txt");

    fin >> B >> G >> TB >> TG;

    int N = B + G;
    vector<int> times;

    // Добавляем времена перехода всех участников
    for (int i = 0; i < B; ++i) times.push_back(TB);
    for (int i = 0; i < G; ++i) times.push_back(TG);

    sort(times.begin(), times.end()); // Сортируем по возрастанию
    int total = 0;

    while (N > 3) {
        int option1 = times[0] + 2 * times[1] + times[N - 1];
        int option2 = 2 * times[0] + times[N - 2] + times[N - 1];
        total += min(option1, option2);
        N -= 2;
    }

    // Осталось 3 или меньше — считаем отдельно
    if (N == 3) {
        total += times[0] + times[1] + times[2];
    } else if (N == 2) {
        total += times[1];
    } else if (N == 1) {
        total += times[0];
    }
    ofstream fout("output.txt");
    fout << total << endl;
    return 0;
}
