#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int index;
};

void selection_sort(vector<Task>& tasks) {
    int N = tasks.size();
    for (int i = 0; i < N - 1; ++i) {
        int max_pos = i;
        for (int j = i + 1; j < N; ++j) {
            if (tasks[j].time > tasks[max_pos].time) {
                max_pos = j;
            }
        }
        swap(tasks[i], tasks[max_pos]);
    }
}

int main() {
    ifstream cin("c.in");
    int N;
    cin >> N;

    vector<Task> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].time;
        tasks[i].index = i + 1;
    }

    selection_sort(tasks);

    ofstream cout("c.out");
    for (int i = 0; i < N; ++i) {
        cout << tasks[i].index << " ";
    }

    return 0;
}
