#include <iostream>
#include <set>
#include <string>
#include <algorithm>

// Функция для генерации перестановок
void generatePermutations(const std::string& input) {
    std::set<std::string> permutations;
    std::string temp = input;

    // Генерация всех перестановок с помощью std::next_permutation
    do {
        permutations.insert(temp);
    } while (std::next_permutation(temp.begin(), temp.end()));

    // Вывод результата
    std::cout << permutations.size() << std::endl;
    for (const auto& perm : permutations) {
        std::cout << perm << std::endl;
    }
}

int main() {
    std::string input;
    std::cin >> input;

    // Проверяем формат ввода (буква, три цифры, две буквы)
    if (input.size() == 6 &&
        isalpha(input[0]) && isdigit(input[1]) && isdigit(input[2]) && isdigit(input[3]) &&
        isalpha(input[4]) && isalpha(input[5])) {

        // Генерация перестановок
        generatePermutations(input);
    } else {
        std::cerr << "Invalid input format" << std::endl;
        return 1;
    }

    return 0;
}
