#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;
    set<string> unique_numbers;

    // Получаем перестановки всех символов (буквы и цифры)
    do {
        // Проверяем, что из полученной перестановки можно собрать корректный номер
        string possible_number = input;
        // Проверяем длину и формат
        if (possible_number.size() == 6) {
            unique_numbers.insert(possible_number);
        }
    } while (next_permutation(input.begin(), input.end())); // генерируем следующую перестановку

    // Выводим результат
    cout << unique_numbers.size() << endl;
    for (const string& num : unique_numbers) {
        cout << num << endl;
    }

    return 0;
}
