#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Информация об одной попытке
struct Attempt {
    int problem; // номер задачи
    int time;    // время отправки (в секундах)
    int result;  // 1 — принято, 0 — отклонено
};

// Информация о команде
struct Team {
    int id;          // номер команды
    int solved;      // количество решённых задач
    long long total; // суммарное время в секундах
};

// Функция для обмена местами двух команд
void swapTeams(Team &a, Team &b) {
    Team temp = a;
    a = b;
    b = temp;
}

// Сравнение двух команд по правилам ACM
bool isBetter(const Team &a, const Team &b) {
    if (a.solved != b.solved)
        return a.solved > b.solved; // больше решённых задач — лучше
    if (a.total != b.total)
        return a.total < b.total;   // меньше общее время — лучше
    return a.id < b.id;             // при равенстве — команда с меньшим номером
}

// Быстрая сортировка (QuickSort)
void quickSort(Team arr[], int left, int right) {
    int i = left, j = right;
    Team pivot = arr[(left + right) / 2]; // опорный элемент

    while (i <= j) {
        while (isBetter(arr[i], pivot)) i++;    // двигаем левый указатель
        while (isBetter(pivot, arr[j])) j--;    // двигаем правый указатель
        if (i <= j) {
            swapTeams(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивно сортируем подмассивы
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    ifstream fin("input.txt");
    int C, N;
    fin >> C >> N; // C — количество команд, N — количество попыток

    // Для каждой команды храним список её попыток
    vector<Attempt> attempts[101];

    // Читаем все попытки
    for (int i = 0; i < N; i++) {
        int c, p, t, r;
        fin >> c >> p >> t >> r;
        Attempt a = {p, t, r};
        attempts[c].push_back(a);
    }

    // Массив для хранения информации о командах
    Team teams[101];

    const int PENALTY = 20 * 60; // штраф 20 минут = 1200 секунд

    // Подсчёт результатов для каждой команды
    for (int team = 1; team <= C; team++) {
        teams[team].id = team;
        teams[team].solved = 0;
        teams[team].total = 0;

        // Проверяем каждую задачу от 1 до 100
        for (int problem = 1; problem <= 100; problem++) {
            int firstAccepted = 1000000000; // время первого принятого решения
            int wrongBefore = 0;            // количество отклонённых попыток до него

            // Находим время первого принятого решения (если есть)
            for (size_t i = 0; i < attempts[team].size(); i++) {
                if (attempts[team][i].problem == problem &&
                    attempts[team][i].result == 1 &&
                    attempts[team][i].time < firstAccepted) {
                    firstAccepted = attempts[team][i].time;
                }
            }

            // Если задача не решена — пропускаем
            if (firstAccepted == 1000000000) continue;

            // Считаем отклонённые попытки ДО принятого решения
            for (size_t i = 0; i < attempts[team].size(); i++) {
                if (attempts[team][i].problem == problem &&
                    attempts[team][i].result == 0 &&
                    attempts[team][i].time < firstAccepted) {
                    wrongBefore++;
                }
            }

            // Добавляем в статистику
            teams[team].solved++;
            teams[team].total += firstAccepted + wrongBefore * PENALTY;
        }
    }

    // Сортировка всех команд по рейтингу (QuickSort)
    quickSort(teams, 1, C);

    ofstream fout("output.txt");
    // Вывод — каждая команда на новой строке
    for (int i = 1; i <= C; i++) {
        fout << teams[i].id;
    }

    return 0;
}
